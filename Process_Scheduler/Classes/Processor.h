#pragma once
#include"..//DataStructures/QueueADT.h"
#include "..//DataStructures/LinkedQueue.h"
#include "..//Supplementary.h"
#include "..//Process.h"

class Processor
{
public:
	Processor();
	virtual void  ScheduleAlgo() = 0;
	~Processor();

private:
	LinkedQueue<int> ReadyQueue;
	Process* RunningProcess;
	State ProcessorState;
	double load;
	double utilization;
};

