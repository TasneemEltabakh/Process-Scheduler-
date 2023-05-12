#pragma once
#include "Classes/Processor.h"
#include "DataStructures/QueueADT.h"
#include "DataStructures/LinkedList.h"
#include "Process.h"
#include "UI.h"
#include <thread>
#include <chrono>
class processor; //dir dec

class Scheduler
{

	
private:
	
	LinkedList<Processor*> ProcessorsList;
	int Numberof_FCFS, Numberof_RR, Numberof_SJF, TotaLNumberOfProcesses;
	LinkedQueue<Process*> NewList;
	LinkedQueue<Process*> Terminal;
	LinkedQueue<Process*> BLK;
	LinkedQueue<Process*> KilledProcesses;
	
	bool stopflag;
	int Timer;
	UI* output;  //r add


public:
	
	Scheduler(string inputfilename);
	Scheduler();
	~Scheduler();
	void load(string inputfilename);
	void TranslateData( string linedata, LinkedQueue<string>* dataP);
	void RemoveParenthesis(string linedata, LinkedQueue<int>* dataProcessor);
	void  CreateProcessors(LinkedQueue<string>* dataProcessor);
	void  InsertProcessToNew(LinkedQueue<string>* dataProcess);
	void  MoveProcessToReadyList();
	void KillSignalSearcher(LinkedQueue<string>* KillData);
	void TimeStepsiterator();
	void  FakeSimulator();
	void KillSignalSearcher();
	
	void fork(Process* p);    // added ariam
	void moveToTrm(Process* p);
};

