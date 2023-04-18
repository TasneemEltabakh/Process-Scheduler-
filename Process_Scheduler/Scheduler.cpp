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


Scheduler::Scheduler(string inputfilename)
{
	load(inputfilename);
	FakeSimulator();
}
Scheduler::Scheduler()
{

}

Scheduler::~Scheduler()
{

}
void Scheduler :: FakeSimulator()
{
    double numOfprocessesAdded = 0;
	Process* added;
	Process* process = new Process;
	Timer = 0;
	int totalnum =Numberof_SJF+Numberof_RR+Numberof_FCFS;
	while (!NewList.IsEmpty())
	{
		
		if (NewList.Peek()->getAT() == Timer)
		{
			NewList.Dequeue_In_Variable(added);
			if (numOfprocessesAdded >= totalnum) {
				numOfprocessesAdded = floor((numOfprocessesAdded-1) / (totalnum));
			}
			ProcessorsList.returnkth(numOfprocessesAdded)->AddToMyReadyList(added);
			numOfprocessesAdded++;
		}
		Timer++;
	}
	for (int i = 0; i < totalnum; i++)
	{
		if (ProcessorsList.returnkth(i)->IsIDlE())
			ProcessorsList.returnkth(i)->AddToRun();
	}
	for (int i = 0; i < totalnum; i++)
	{
		int random = 1 + (rand() % 100);
		process = ProcessorsList.returnkth(i)->RunningNow();
		if (random >= 1 && random <= 15)
		{
			BLK.enqueue(process);
			ProcessorsList.returnkth(i)->RunningIsFree();
		}
		else if (random >= 20 && random <= 30)
		{
			ProcessorsList.returnkth(numOfprocessesAdded)->AddToMyReadyList(process);
			numOfprocessesAdded++;
			ProcessorsList.returnkth(i)->RunningIsFree();
		}
		else if (random >= 50 && random <= 60)
		{
			Terminal.enqueue(process);
			ProcessorsList.returnkth(i)->RunningIsFree();
		}

	}
	int random = 1 + (rand() % 100);
	if (random < 10)
	{
		BLK.Dequeue_In_Variable(process);
		ProcessorsList.returnkth(numOfprocessesAdded)->AddToMyReadyList(process);
		numOfprocessesAdded++;

	}



}
void Scheduler ::TimeStepsiterator()
{
	
	
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
void Scheduler ::TranslateData(string& linedata, LinkedQueue<string>*  dataP) //this Function Splits the string of one line into information for the system
{
	stringstream s(linedata);


	int num;
	while (s >> num) {
		
		dataP->enqueue(to_string(num));
		
	}
}
void Scheduler::RemoveParenthesis(string linedata, LinkedQueue<int>* dataProcessor)
{
	int n1 = linedata.find("(");
	int n2 = linedata.find(")");
	int n3 = linedata.find(",");
	string FirstNumber, SecondNumber;
	for (int i = n1 + 1; i < n3; i++)
	{
		FirstNumber = FirstNumber + linedata.at(i);
		
	}
	for (int i = n3 + 1; i < n2; i++)
	{
		SecondNumber = SecondNumber + linedata.at(i);

	}
	dataProcessor->enqueue(stoi(FirstNumber));
	dataProcessor->enqueue(stoi(SecondNumber));

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


	for (int i = 0; i < Numberof_RR; i++)
	{
		ProcessorsList.InsertBeg(new RoundRobinProcessor(stoi(slicetime), stoi( rtf)));
	}
	for (int i = 0; i < Numberof_SJF; i++)
	{
		ProcessorsList.InsertBeg(new ShortestJobProcessor());
	}
	for (int i = 0; i < Numberof_FCFS; i++)
	{
		ProcessorsList.InsertBeg(new FirstComeProcessor(stoi(maxw),stoi(fork)));
	}
	
}
void Scheduler::InsertProcessToNew(LinkedQueue<string>* dataProcess)
{
	string At, id, ct, nio;
	//int IoR, IoD;

	dataProcess->Dequeue_In_Variable(At);
	dataProcess->Dequeue_In_Variable(id);
	dataProcess->Dequeue_In_Variable(ct);
	dataProcess->Dequeue_In_Variable(nio);

	Process* newprocess = new Process(stoi(At), stoi(id), stoi(ct), stoi(nio));
	
	/*if (stoi(nio) != 0)
	{
		LinkedQueue<int>* Data = new LinkedQueue<int>;
		dataProcess->Dequeue_In_Variable(iop);
		RemoveParenthesis(iop, Data);
		Data->Dequeue_In_Variable(IoR);
		Data->Dequeue_In_Variable(IoD);
		delete Data;
		newprocess->InsertToIOlist(IoR, IoD);
		cout << IoR << IoD;
	}*/

	NewList.enqueue(newprocess);

}

void Scheduler::KillSignalSearcher(LinkedQueue<string>* KillData)
{
	//string time, id;
	//KillData->Dequeue_In_Variable(time);
	//KillData->Dequeue_In_Variable(id);
	//cout << time;
	//cout << endl;
	//cout << id;
	//if (Timer == stoi(time))
	//{
	//	for (int i = 0; i < Numberof_FCFS; i++)
	//	{

	//		FirstComeProcessor* childPointer = dynamic_cast<FirstComeProcessor*>(ProcessorsList.returnkth(i));
	//		childPointer->~FirstComeProcessor();
	//		if (childPointer->IsThereKilled(stoi(id)))
	//		{
	//			KilledProcesses.enqueue(childPointer->KillSignal());
	//		}
	//	}
	//}
}
void  Scheduler:: MoveProcessToReadyList()
{
	
}
