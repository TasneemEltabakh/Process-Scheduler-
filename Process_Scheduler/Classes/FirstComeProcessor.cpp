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
	ReadyQueue.Dequeue_In_Variable(RunningProcess);

	while (RunningProcess->getCT() != 0 ) {

		//runingTime++;
		RunningProcess->setCT(RunningProcess->getCT() - 1);
	}
	//Here the previuse must go to TERM
	ReadyQueue.Dequeue_In_Variable(RunningProcess);
}

void  FirstComeProcessor::SetMAXW(int max)
{
	maxw = max;
}


void FirstComeProcessor::ForkingCheck() {

	int random = 1 + (rand() % 100);

	if (random <= forkprob) 
	{
		RunningProcess->SetFOrk();

		//Scheduler* sch ;
		//sch->fork(RunningProcess);
		//delete sch;
	};

}
