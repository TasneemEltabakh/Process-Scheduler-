#pragma once
#include"..//DataStructures/QueueADT.h"
#include "..//DataStructures/LinkedQueue.h"

class Processor
{
public:
	Processor();
	virtual void  ScheduleAlgo() = 0;
	~Processor();
private:
	LinkedQueue<int> ReadyQueue;
	bool State;
	double load;
	double utilization;
};

