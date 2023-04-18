#pragma once
#include"..//DataStructures/QueueADT.h"
#include "..//DataStructures/LinkedQueue.h"
#include "..//DataStructures/LinkedList.h"
#include "..//Supplementary.h"
#include "..//Process.h"
#include "..//Scheduler.h"

class Processor
{
public:
	Processor();
	virtual void  ScheduleAlgo() = 0;
	~Processor();

protected:
	Scheduler* sch;
	Process* RunningProcess;
	State ProcessorState;
	double load;
	double utilization;
	int TimerOfReadyList;
    int countOfProcesses;
	int runingTime;
};

