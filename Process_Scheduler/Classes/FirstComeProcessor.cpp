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
	if (ReadyQueue.isEmpty()) {
		return;
	}

	ReadyQueue.dequeue(RunningProcess);

	for (int i = 0; i < RunningProcess->getCT(); i++) {
		runingTime++;
	}

	sch->moveToTrm(RunningProcess);

	ScheduleAlgo();
}

void  FirstComeProcessor::SetMAXW(int max)
{
	maxw = max;
}

void FirstComeProcessor::ForkingCheck() {

	int random = 1 + (rand() % 100);

	if (random <= forkprob) 
	{
		sch->fork(RunningProcess);

	};
}

