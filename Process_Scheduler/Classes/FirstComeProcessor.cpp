#include "FirstComeProcessor.h"



FirstComeProcessor::FirstComeProcessor(int max, int fork)
{
	forkprob = fork;
	maxw = max;
	countOfProcesses = 0;
}
FirstComeProcessor::FirstComeProcessor()
{
	
}

FirstComeProcessor::~FirstComeProcessor()
{

}

void FirstComeProcessor::ScheduleAlgo()
{
	//cout << "HI this is Algo for first come" << endl;
	
	//ReadyQueue->Dequeue_In_Variable(RunningProcess);
	if (ReadyQueue.IsEmpty()) {
		return;
	}

	ReadyQueue.Dequeue_In_Variable(RunningProcess);

	while (RunningProcess->getCT() != 0 ) {

		//runingTime++;
		RunningProcess->setCT(RunningProcess->getCT() - 1);
	}
	//Here the previuse must go to TERM
	ReadyQueue.Dequeue_In_Variable(RunningProcess);
}

void FirstComeProcessor::SetMAXW(int max)
{
	maxw = max;
}
bool FirstComeProcessor::IsThereKilled(int idOfProcess)
{
	for (int i = 0; i < ReadyQueue.Count(); i++)
	{
		if (ReadyQueue.returnkth(i)->getPID() == idOfProcess)
		{
			KilledOne = ReadyQueue.returnkth(i);
			ReadyQueue.DeleteNode(ReadyQueue.returnkth(i));
			return true;
		}
	}
	return false;
}
Process* FirstComeProcessor:: KillSignal()
{
	return KilledOne;
}
Process* FirstComeProcessor::MoveMeToTerminal()
{
	TerminatProcess = RunningProcess;
	RunningIsFree();
	AddToRun();
	return TerminatProcess;
}

/*void FirstComeProcessor::ForkingCheck() {


	if (random <= forkprob) 
	{
		RunningProcess->SetFOrk();

		//Scheduler* sch ;
		//sch->fork(RunningProcess);
		//delete sch;
};*/

//void FirstComeProcessor::ForkingCheck() {
//
//	int random = 1 + (rand() % 100);
//
//	if (random <= forkprob) 
//	{
//		//Scheduler* sch ;
//		//sch->fork(RunningProcess);
//		//delete sch;
//	};
//}
void  FirstComeProcessor::AddToMyReadyList(Process* NewProcess)
{
	countOfProcesses++;
	ReadyQueue.InsertBeg(NewProcess);
	cout << "HI this is Algo for first come" << endl;
	
}
void FirstComeProcessor::AddToRun()
{
	ProcessorState = busy;
	RunningProcess = ReadyQueue.returnkth(0);
	downtimer = RunningProcess->getCT();
	ReadyQueue.DeleteFirst();

}
int FirstComeProcessor::getcount()
{
	return ReadyQueue.Count();
}
Process* FirstComeProcessor::getkth(int k)
{
	return ReadyQueue.returnkth(k);
}

bool FirstComeProcessor::CheckIfemptyready()
{
	if (ReadyQueue.IsEmpty())
		return true;
	return false;
}