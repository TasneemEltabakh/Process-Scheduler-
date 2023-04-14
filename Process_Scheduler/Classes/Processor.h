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
	void TimerCalculator();
private:
	LinkedQueue<Process>* ReadyQueue = new LinkedQueue<Process>;
	State ProcessorState;
	double load;
	double utilization;
	int TimerOfReadyList;
    int countOfProcesses;

};

