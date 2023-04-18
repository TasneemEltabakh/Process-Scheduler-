#pragma once
#include "Classes/Processor.h"
#include "DataStructures/QueueADT.h"
#include "DataStructures/LinkedList.h"
#include "Process.h"
#include "UI.h"
class processor; //dir dec

class Scheduler
{
protected:
	
private:
	
	LinkedList<Processor*> ProcessorsList;
	int Numberof_FCFS, Numberof_RR, Numberof_SJF, TotaLNumberOfProcesses;
	LinkedQueue<Process*> NewList;
	LinkedQueue<Process*> Terminal;
	LinkedQueue<Process*> BLK;
	LinkedQueue<Process*> KilledSignal;
	int CurrentTime;  //R add

	UI* output;  //r add


public:
	//LinkedList<Processor*> ProcessorsList;
	//int Numberof_FCFS, Numberof_RR, Numberof_SJF, TotaLNumberOfProcesses;
	//LinkedQueue<Process*> NewList;
	//LinkedQueue<Process*> Terminal;
	//LinkedQueue<Process*> BLK;
	//LinkedQueue<Process*> KilledSignal;
	//int CurrentTime;  //R add



	Scheduler(string inputfilename);
	~Scheduler();
	void load(string inputfilename);
	void TranslateData(string linedata, LinkedQueue<string>* dataProcessor);
	void RemoveParenthesis(string linedata, LinkedQueue<int>* dataProcessor);
	void  CreateProcessors(LinkedQueue<string>* dataProcessor);
	void  InsertProcessToNew(LinkedQueue<string>* dataProcess);
	void KillSignalSearcher();
	
	void fork(Process* p);    // added ariam
	int getCurrentTime();  //R add
};

