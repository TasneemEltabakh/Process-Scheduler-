#pragma once
#include "Classes/Processor.h"
#include "DataStructures/QueueADT.h"
#include "DataStructures/LinkedList.h"
#include "Process.h"

class processor; //dir dec

class Scheduler
{
private:
	//Processor** ProcessorsList = new Processor * [3];
	LinkedList<Processor*> ProcessorsList;
	int Numberof_FCFS, Numberof_RR, Numberof_SJF, TotaLNumberOfProcesses;
	LinkedQueue<Process*> NewList;
	LinkedQueue<Process*> Terminal;
	LinkedQueue<Process*> BLK;
	LinkedQueue<Process*> KilledSignal;

public:
	Scheduler(string inputfilename);
	~Scheduler();
	void load(string inputfilename);
	void TranslateData(string linedata, LinkedQueue<string>* dataProcessor);
	void RemoveParenthesis(string linedata, LinkedQueue<int>* dataProcessor);
	void  CreateProcessors(LinkedQueue<string>* dataProcessor);
	void  InsertProcessToNew(LinkedQueue<string>* dataProcess);
	void KillSignalSearcher();
	void MoveFromNewToRdy(int Now_Time_step);
};

