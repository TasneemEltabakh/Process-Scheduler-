#include "FirstComeProcessor.h"

FirstComeProcessor::FirstComeProcessor(int max, int fork)
{
	forkprob = fork;
	maxw = max;
}

FirstComeProcessor::~FirstComeProcessor()
{

}

void FirstComeProcessor::ScheduleAlgo()
{
	ReadyQueue.dequeue(RunningProcess);

	while (RunningProcess->getCT() != 0 ) {

			runingTime++;
	}
}

void  FirstComeProcessor::SetMAXW(int max)
{
	maxw = max;
}

void FirstComeProcessor::ForkingCheck() {

	int random = 1 + (rand() % 100);

	if (random <= forkprob) 
	{
		//Scheduler* sch ;
		//sch->fork(RunningProcess);
		//delete sch;
	};
}
