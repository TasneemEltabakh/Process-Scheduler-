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

	Timer = 0;
	stopflag = false;
	load(inputfilename);

}
void Scheduler::Run()
{
	
	while (true)
	{

		updateTimer();
		cout << Timer;
		MoveProcessToReadyList();

	}
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
				KillSignalSearcher(Data);
				
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
			
		
		}
		else {
			
			Data->enqueue(word);
			
		
		}
	
	
	}
}

void  Scheduler:: CreateProcessors(LinkedQueue<string>* dataProcessor) //this function Creates processors of each type by the required count and adds them to the processors list 
{
	string slicetime, rtf, fork, stl, maxw, Numberof_FC, Numberof_SJ, Numberof_R;
	dataProcessor->Dequeue_In_Variable(Numberof_FC);
	dataProcessor->Dequeue_In_Variable(Numberof_SJ);
	dataProcessor->Dequeue_In_Variable(Numberof_R);
	dataProcessor->Dequeue_In_Variable(slicetime);
	dataProcessor->Dequeue_In_Variable(rtf);
	dataProcessor->Dequeue_In_Variable(maxw);
	dataProcessor->Dequeue_In_Variable(stl);
	dataProcessor->Dequeue_In_Variable(fork);
	Numberof_SJF = stoi(Numberof_SJ);
	Numberof_RR = stoi(Numberof_R);
	Numberof_FCFS = stoi(Numberof_FC);

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
		}
	
	}

	NewList.enqueue(newprocess);

}

void Scheduler::KillSignalSearcher(LinkedQueue<string>* KillData)
{
	if (KillData->IsEmpty()) {
		
		return;
	}
	string time, id;
	KillData->Dequeue_In_Variable(time);
	KillData->Dequeue_In_Variable(id);
	
	if (Timer == stoi(time))
	{
		for (int i = 0; i < Numberof_FCFS; i++)
		{

			FirstComeProcessor* childPointer = dynamic_cast<FirstComeProcessor*>(ProcessorsList.returnkth(i));
			if (childPointer->IsThereKilled(stoi(id)))
			{
				return;
			}


			
		}
	}
}
int Scheduler::ShortestQueue()
{
	LinkedList<Processor*>copy(ProcessorsList);
	Processor* currentprocessor;
	copy.Dequeue_In_Variable(currentprocessor);
	int min= currentprocessor->getExpectedTime();
	int i = 0;
	///*while(copy.Dequeue_In_Variable(currentprocessor))*/
	//{
	//	if (currentprocessor->getExpectedTime() < min) {
	//		min = currentprocessor->getExpectedTime();
	//		i++;
	//	}
	//}
	cout << i << endl;
	return i;
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
			cout << "now we insert a process with id" << process->getPID();
		
			
		}

	}
	
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
