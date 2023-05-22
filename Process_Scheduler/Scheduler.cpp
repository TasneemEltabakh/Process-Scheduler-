#include "Scheduler.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Process.h"
#include "Classes/FirstComeProcessor.h"
#include "Classes/RoundRobinProcessor.h"
#include "Classes/ShortestJobProcessor.h"
#include "Classes/Processor.h"
#include "UI.h"
#include <windows.h>
#include <thread>
#include <chrono>



using namespace std;

Scheduler::Scheduler(string inputfilename)
{
	loop = 1;
	Timer = 0;
	stopflag = false;
	Forked = 0;
	load(inputfilename);

}
void Scheduler::Run()
{

	while (ISstop())
	{

		updateTimer();
		MoveProcessToReadyList();
		for (int i = 0; i < ProcessorsList.Count(); i++)
		{
			ProcessorsList.returnkth(i)->CurrentTime(Timer);

		}

		for (int i = 0; i < ProcessorsList.Count(); i++)
		{
			Processor* processor = ProcessorsList.returnkth(i);
			processor->ScheduleAlgo();
		}
		srand(time(0));
		for (int i = 0; i < Numberof_FCFS; i++)
		{

			FirstComeProcessor* ForkingProcess = dynamic_cast<FirstComeProcessor*>(ProcessorsList.returnkth(i));
			
			int x = rand() % 100;
			if (ForkingProcess->ISforked(x))
			{
				Forked++;
				TotaLNumberOfProcesses++;
				int AT = Timer;
				int pid = TotaLNumberOfProcesses + 1;
				TotaLNumberOfProcesses = TotaLNumberOfProcesses + 1;;
				int nio = 0;
				int ct = ForkingProcess->returnMyRunningCT();
				cout <<"DATA OF FORKED PRECESS" << AT <<" "<< pid << " " << ct << " " << nio << " " << endl;
				Process* forkedProcess = new Process(AT, pid, ct, nio);
				MoveProcessToReadyFirstOnly(forkedProcess);
				ForkingProcess->SetToRunningChild(forkedProcess);

			}

		}

		if (Timer == (STL * loop))
		{
			WorkStealing();
			loop++;
		}

		ForOutPutFile();
		IORequestNeeded();
		countDownBLK();
		Overheating();
		KillSignalSearcher();

		output->OutPutScreen(Terminal, BLK, ProcessorsList, TotaLNumberOfProcesses, Numberof_SJF, Numberof_FCFS, Numberof_RR, Timer);
		system("pause");
	}
	
}

bool Scheduler::ISstop() {  //for UI
	if ((Terminal.Count()- ProcessorsList.Count())== TotaLNumberOfProcesses) {
		return false;
	}
	return true;
}
Scheduler::~Scheduler()
{
	stopflag = true;

}
void Scheduler::updateTimer()
{
	Timer++;
}
void Scheduler::load(string inputfile)
{
	ifstream InputFile;
	int counter=0;
	InputFile.open(inputfile+ ".txt");

	if (InputFile.is_open()) {
		
			string* line = new string;
			LinkedQueue<string>* Data = new LinkedQueue<string>;

	
			for (int i = 0; i < 3; i++)
			{
				counter++;
				getline(InputFile, *line);
				TranslateData(*line, Data);
			}
			if (counter == 3) {
				CreateProcessors(Data); 
				counter++;
			}
			if (counter == 4) {
				getline(InputFile, *line); 
				TotaLNumberOfProcesses = stoi(*line);
				
			}
			for (int i = 0; i < TotaLNumberOfProcesses; i++)
			{
				getline(InputFile, *line);
				TranslateData(*line, Data);
				InsertProcessToNew(Data);
				counter++;
			}
			while (!InputFile.eof())
			{
				getline(InputFile, *line);
				TranslateData(*line, Data);
				KillSignal(Data);

			}
	}
	else {
		cout << "Couldn't open file\n";
	}
	InputFile.close();
	
}
void Scheduler::TranslateData(string line, LinkedQueue<string>* Data)
{
	istringstream iss(line);
	string word;

	while (iss >> word)
	{
		if (word.front() == '(' && word.back() == ')') {
		
			int comma_pos = word.find(',');
			string first = word.substr(1, comma_pos - 1);
			string second = word.substr(comma_pos + 1, word.size() - comma_pos - 2);
			
			Data->enqueue(first);
			Data->enqueue(second);
			cout << first << endl;
			cout << first << endl;
			
		
		}
		else {
			
			Data->enqueue(word);

		}
	
	
	}
}

void  Scheduler:: CreateProcessors(LinkedQueue<string>* dataProcessor) //this function Creates processors of each type by the required count and adds them to the processors list 
{
	string slicetime, rtf, stl, heat, fork, maxw, breakTime, Numberof_FC, Numberof_SJ, Numberof_R;
	dataProcessor->Dequeue_In_Variable(Numberof_FC);
	dataProcessor->Dequeue_In_Variable(Numberof_SJ);
	dataProcessor->Dequeue_In_Variable(Numberof_R);
	dataProcessor->Dequeue_In_Variable(slicetime);
	dataProcessor->Dequeue_In_Variable(rtf);
	dataProcessor->Dequeue_In_Variable(maxw);
	dataProcessor->Dequeue_In_Variable(stl);
	dataProcessor->Dequeue_In_Variable(fork);
	dataProcessor->Dequeue_In_Variable(heat);
	dataProcessor->Dequeue_In_Variable(breakTime);
	Numberof_SJF = stoi(Numberof_SJ);
	Numberof_RR = stoi(Numberof_R);
	Numberof_FCFS = stoi(Numberof_FC);
	STL = stoi(stl);
	Heatingprop = stoi(heat);
	timeOfRelaxing = stoi(breakTime);

	for (int i = 0; i < Numberof_FCFS; i++)
	{
		ProcessorsList.InsertEnd(new FirstComeProcessor(stoi(maxw), stoi(fork)));
	}

	for (int i = 0; i < Numberof_SJF; i++)
	{
		ProcessorsList.InsertEnd(new ShortestJobProcessor());
	}
	for (int i = 0; i < Numberof_RR; i++)
	{
		ProcessorsList.InsertEnd(new RoundRobinProcessor(stoi(slicetime), stoi(rtf)));
	}
}
void Scheduler::InsertProcessToNew(LinkedQueue<string>* dataProcess)
{
	string At, id, ct, nio;
	string IoR, IoD;

	dataProcess->Dequeue_In_Variable(At);
	dataProcess->Dequeue_In_Variable(id);
	dataProcess->Dequeue_In_Variable(ct);
	dataProcess->Dequeue_In_Variable(nio);

	Process* newprocess = new Process(stoi(At), stoi(id), stoi(ct), stoi(nio));
	
	if (stoi(nio) != 0)
	{
		for (int i = 0; i < stoi(nio); i++)
		{
			dataProcess->Dequeue_In_Variable(IoR);
			dataProcess->Dequeue_In_Variable(IoD);
			newprocess->addDatatoIOPairs(stoi(IoR), stoi(IoD));
			cout << "the process id" << id << "is created with request at " << IoR << "for" << IoD << endl;
		}
	
	}

	NewList.enqueue(newprocess);

}
void Scheduler::KillSignalSearcher()
{
	int x;
	if(!KilledProcesses.IsEmpty()){
	x = KilledProcesses.Peek();
	if (x == Timer)
	{
		KilledProcesses.Dequeue_In_Variable(x);
		KilledProcesses.Dequeue_In_Variable(x);
		for (int i = 0; i < Numberof_FCFS; i++)
		{
			
			FirstComeProcessor * child = dynamic_cast<FirstComeProcessor*>(ProcessorsList.returnkth(i));
			child->IsThereKilled(x);

		}
	}
	}

}
void Scheduler::KillSignal(LinkedQueue<string>* KillData)
{

	string time, id;
	KillData->Dequeue_In_Variable(time);
	KillData->Dequeue_In_Variable(id);

	KilledProcesses.enqueue(stoi(time));
	KilledProcesses.enqueue(stoi(id));
	
}
int Scheduler::ShortestQueue()
{
	int min = INT_MAX;
	int shortestIndex = -1;
	cout << "shortest queue time" << min << endl;
	for (int i = 0; i < ProcessorsList.Count(); i++)
	{
		cout << "shortest queue time" << min << endl;
		if (!ProcessorsList.returnkth(i)->StoppedCheck())
		{

			int expectedTime = ProcessorsList.returnkth(i)->getExpectedTime();
			if (expectedTime < min)
			{
				min = expectedTime;
				shortestIndex = i;
			}
		}
	}
	cout << "shortest queue index" << shortestIndex << endl;
	return shortestIndex;
}
int Scheduler::ShortestFCFSQueue()
{
	int min = INT_MAX;
	int shortestIndex = -1;
	
	for (int i = 0; i < Numberof_FCFS; i++)
	{
		
		if (!ProcessorsList.returnkth(i)->StoppedCheck())
		{

			int expectedTime = ProcessorsList.returnkth(i)->getExpectedTime();
			if (expectedTime < min)
			{
				min = expectedTime;
				shortestIndex = i;
			}
		}
	}
	
	return shortestIndex;
}

int Scheduler::LongestQueue()
{

	int max = ProcessorsList.returnkth(0)->getExpectedTime();
	int LongestIndex = 0;

	for (int i = 1; i < ProcessorsList.Count(); i++)
	{
		if (ProcessorsList.returnkth(i)->StoppedCheck() == false)
		{

			if (ProcessorsList.returnkth(i)->getExpectedTime() > max)
			{
				max = ProcessorsList.returnkth(i)->getExpectedTime();
				LongestIndex = i;
			}
		}
	}

	return LongestIndex;
}
int Scheduler::LongestQueueTime()
{

	int max = ProcessorsList.returnkth(0)->getExpectedTime();
	

	for (int i = 1; i < ProcessorsList.Count(); i++)
	{
		if (ProcessorsList.returnkth(i)->StoppedCheck() == false)
		{

			if (ProcessorsList.returnkth(i)->getExpectedTime() > max)
			{
				max = ProcessorsList.returnkth(i)->getExpectedTime();

			}
		}
	}

	return max;
}
int Scheduler::ShortestQueueTime()
{
	if (ProcessorsList.Count() == 0)
	{
		return -1;
	}

	int min = ProcessorsList.returnkth(0)->getExpectedTime();


	for (int i = 1; i < ProcessorsList.Count(); i++)
	{
		if (ProcessorsList.returnkth(i)->StoppedCheck()==false)
		{
			if (ProcessorsList.returnkth(i)->getExpectedTime() < min)
			{
				min = ProcessorsList.returnkth(i)->getExpectedTime();

			}
		}
	}

	return min;
}
void Scheduler::ForOutPutFile()
{
	for (int i = 0; i < ProcessorsList.Count(); i++)
	{
		if (ProcessorsList.returnkth(i)->getTerminal() != nullptr)
		{
			Terminal.enqueue(ProcessorsList.returnkth(i)->getTerminal());
		}
	}
}
bool Scheduler::isAllEmpty()
{

	for (int i = 0; i < ProcessorsList.Count(); i++)
	{
		if (!ProcessorsList.returnkth(i)->isthisProcessrEmpty())
		{
			return false;
		}
	}
	return true;
}
void Scheduler::WorkStealing()
{
	if (isAllEmpty()) return;
	else
	{
		int index_S = ShortestQueue();
		int index_L = LongestQueue();
		double longest_T = LongestQueueTime();
		int Shortest_T = ShortestQueueTime();

		int steal_limit = ((longest_T - Shortest_T) / longest_T) * 100;
		while (steal_limit > 40)
		{
			Process* stolen = new Process(*ProcessorsList.returnkth(index_L)->RemoveProcess());
			ProcessorsList.returnkth(index_S)->AddToMyReadyList(*stolen);
			if (stolen->getstolen() == 0) Stolen++;
			index_S = ShortestQueue();
			index_L = LongestQueue();
			steal_limit = (LongestQueueTime() - ShortestQueueTime()) / LongestQueueTime();

		}
		
	}
}
void Scheduler::Overheating()
{
	srand(time(0));

	for (int i = 0; i < ProcessorsList.Count(); i++)
	{
		Processor* currentProcessor = ProcessorsList.returnkth(i);
		if (!currentProcessor->StoppedCheck())
		{
			int random = 1 + (rand() % 700);
			
			if (random == Heatingprop)
			{
				currentProcessor->OutOfService(timeOfRelaxing);

				int shortestIndex = ShortestQueue();
				Processor* shortestProcessor = ProcessorsList.returnkth(shortestIndex);

				while (currentProcessor->getcount() > 0)
				{
					Process* movedProcess = currentProcessor->RemoveProcess();
					shortestProcessor->AddToMyReadyList(*movedProcess);
				}
			}
		}
		else
		{
			int remainingBreakTime = currentProcessor->CountDownBreak();
			if (remainingBreakTime == 0)
			{
				currentProcessor->BacktoService();
				
			}
		}
	}
}

void Scheduler::IORequestNeeded()
{
	for (int i = 0; i < ProcessorsList.Count(); i++)
	{
		if (ProcessorsList.returnkth(i)->getIO() != nullptr)
		{
			//Process* newprocess = new Process(*ProcessorsList.returnkth(i)->getIO());
			ProcessorsList.returnkth(i)->getIO()->seeDurationForAskForIO();
			BLK.enqueue(ProcessorsList.returnkth(i)->getIO());
		}
	}
}

void Scheduler::countDownBLK()
{
	if (!BLK.IsEmpty()) {
		for (int i = 0; i < BLK.Count(); i++)
		{
			Process* process;

			process = BLK.Peek();
			

			if (process->get_duration() != 0)
			{
				if (c == 0) {  //R add
					process->setIO_D(process->get_duration());
				}
				process->downDuration();
			}
			else if (process->get_duration() == 0)
			{
				BLK.Dequeue_In_Variable(process);
				process->setdurationtozero();
				MoveProcessToReadyListAgain(process);
				c = 0;/// R add
			}
		}
	}
	else
		return;

}




void Scheduler:: MoveProcessToReadyList()
{
	Process* process;
	
	if (!NewList.IsEmpty())
	{

		if (NewList.Peek()->getAT() == Timer)
		{

			NewList.Dequeue_In_Variable(process);
			ProcessorsList.returnkth(ShortestQueue())->AddToMyReadyList(*process);
		
		}
		

	}
	
}
void Scheduler::MoveProcessToReadyListAgain(Process* p)
{
	int shortestQueueIndex = ShortestQueue();
	ProcessorsList.returnkth(shortestQueueIndex)->AddToMyReadyList(*p);
}
void Scheduler::MoveProcessToReadyFirstOnly(Process* p)
{
	int shortestQueueIndex = ShortestFCFSQueue();
	ProcessorsList.returnkth(shortestQueueIndex)->AddToMyReadyList(*p);
}
int Scheduler::CalculateForkPercentage()
{
	double forkedpercentage = (Forked / TotaLNumberOfProcesses) * 100;
	return forkedpercentage;
}

//void Scheduler::FakeSimulator()
//{
//	bool flag = true;
//	while (flag)
//	{
//		srand(time(0));
//		double numOfprocessesAdded = 0;
//		Process* added;
//		Process* process = new Process;
//		int totalnum = Numberof_SJF + Numberof_RR + Numberof_FCFS;
//		int timerun = 3;
//		int terminatedcount = 0;
//		int countflag = 0;
//		while (!NewList.IsEmpty())
//		{
//
//			if (NewList.Peek()->getAT() == Timer)
//			{
//				NewList.Dequeue_In_Variable(added);
//				if (numOfprocessesAdded >= totalnum) {
//					numOfprocessesAdded = floor((numOfprocessesAdded - 1) / (totalnum));
//				}
//				ProcessorsList.returnkth(numOfprocessesAdded)->AddToMyReadyList(added);
//				numOfprocessesAdded++;
//			}
//			Timer++;
//		}
//
//		for (int i = 0; i < totalnum; i++)
//		{
//
//			if (ProcessorsList.returnkth(i)->IsIDlE())
//			{
//
//				if (!ProcessorsList.returnkth(i)->CheckIfemptyready()) {
//					ProcessorsList.returnkth(i)->AddToRun();
//					countflag++;
//				}
//				else
//				{
//					timerun--;
//				}
//			}
//			else
//			{
//				timerun--;
//			}
//			if (timerun <= 0) {
//
//				Terminal.enqueue(ProcessorsList.returnkth(i)->MoveMeToTerminal()); cout << "terminated from loop" << endl;
//
//			}
//		}
//		for (int i = 0; i < totalnum; i++)
//		{
//			while (!ProcessorsList.returnkth(i)->CheckIfemptyready())
//			{
//				int random = 1 + (rand() % 100);
//				process = ProcessorsList.returnkth(i)->RunningNow();
//				if (random >= 1 && random <= 15)
//				{
//					BLK.enqueue(process);
//					ProcessorsList.returnkth(i)->RunningIsFree();
//					if (!ProcessorsList.returnkth(i)->CheckIfemptyready()) ProcessorsList.returnkth(i)->AddToRun();
//					cout << "blocked" << endl;
//				}
//				else if (random >= 20 && random <= 30)
//				{
//					cout << "AddedToReadyQueueAgain" << endl;
//					ProcessorsList.returnkth(numOfprocessesAdded)->AddToMyReadyList(process);
//					ProcessorsList.returnkth(i)->RunningIsFree();
//					if (!ProcessorsList.returnkth(i)->CheckIfemptyready()) ProcessorsList.returnkth(i)->AddToRun();
//					numOfprocessesAdded++;
//
//				}
//				else if (random >= 50 && random <= 60)
//				{
//					Terminal.enqueue(process);
//					ProcessorsList.returnkth(i)->RunningIsFree();
//					if (!ProcessorsList.returnkth(i)->CheckIfemptyready()) ProcessorsList.returnkth(i)->AddToRun();
//					cout << "terminated" << endl;
//					terminatedcount++;
//				}
//			}
//
//			int random = 1 + (rand() % 100);
//			if (random < 10)
//			{
//				if (!BLK.IsEmpty()) {
//					BLK.Dequeue_In_Variable(process);
//					ProcessorsList.returnkth(numOfprocessesAdded)->AddToMyReadyList(process);
//					numOfprocessesAdded++;
//				}
//
//			}
//			for (int i = 0; i < Numberof_FCFS; i++)
//			{
//				random = 1 + (rand() % 10);
//				FirstComeProcessor* childPointer = dynamic_cast<FirstComeProcessor*>(ProcessorsList.returnkth(0));
//				if (!ProcessorsList.returnkth(i)->CheckIfemptyready())
//				{
//					if (childPointer->IsThereKilled(random))
//						Terminal.enqueue(childPointer->KillSignal());
//				}
//			}
//			output->OutPutScreen(Terminal, BLK, ProcessorsList, TotaLNumberOfProcesses, Numberof_SJF, Numberof_FCFS, Numberof_RR, Timer);
//			system("pause");
//		}
//
//		if (Terminal.Count() == TotaLNumberOfProcesses) flag = false;
//		Timer++;
//	}
//}
//
//
//
//
//


