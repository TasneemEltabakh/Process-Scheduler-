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
	LinkedQueue<int> KilledProcesses;
	bool stopflag;  //************
	int Timer;
	UI* output;
	void updateTimer();
	int STL;
	int Heatingprop;
	int timeOfRelaxing;
	int loop;
	int c; //I needed it in countDownBLK for UI
	double Forked;
	double Stolen;
	double killed;

public:
	
	Scheduler(string inputfilename);
	Scheduler();
	~Scheduler();
	void Run();
	void MoveProcessToReadyFirstOnly(Process* p);
	int ShortestFCFSQueue();
	void load(string inputfilename);
	void TranslateData( string linedata, LinkedQueue<string>* dataP);
	void RemoveParenthesis(string linedata, LinkedQueue<int>* dataProcessor);
	void  CreateProcessors(LinkedQueue<string>* dataProcessor);
	void  InsertProcessToNew(LinkedQueue<string>* dataProcess);
	void  MoveProcessToReadyList();
	void MoveProcessToReadyListAgain(Process*);
	void KillSignal(LinkedQueue<string>* KillData);
	void KillSignalSearcher();
	void TimeStepsiterator();
	void  FakeSimulator();
	void getTime() const;
	void ForOutPutFile();
	bool isAllEmpty();
	void Overheating();
	void fork(Process* p);  
	int ShortestQueue();
	int LongestQueue();
	void moveToTrm(Process* p);
	void WorkStealing();
	int ShortestQueueTime();
	int LongestQueueTime();
	void IORequestNeeded();
	void countDownBLK();
	//void KillOrohan();
	bool ISstop();  //for UI
	int CalculateForkPercentage();
	int CalculateStealingPercentage();
	int CalculateKillingPercentage();
	void ForOutPutFileForKilled();
};
