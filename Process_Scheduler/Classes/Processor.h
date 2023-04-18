#pragma once
#include"..//DataStructures/QueueADT.h"
#include "..//DataStructures/LinkedQueue.h"
#include "..//DataStructures/LinkedList.h"
#include "..//Supplementary.h"
#include "..//Process.h"

class Processor
{
public:
	Processor();
	virtual void  ScheduleAlgo() = 0;
	~Processor();
	virtual void  AddToMyReadyList(Process* NewProcess) = 0;
    Process* MoveMeToTerminal();
	
protected:
	Process* RunningProcess;
	State ProcessorState;
	double load;
	double utilization;
	int TimerOfReadyList;
    int countOfProcesses;

	int runingTime;
};

