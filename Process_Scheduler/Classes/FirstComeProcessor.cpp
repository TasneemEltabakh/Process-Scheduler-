#include "FirstComeProcessor.h"

FirstComeProcessor::FirstComeProcessor(int max, int fork)
{
	forkprob = fork;
	maxw = max;
}
FirstComeProcessor::FirstComeProcessor()
{
	
}

FirstComeProcessor::~FirstComeProcessor()
{

}

void FirstComeProcessor::ScheduleAlgo()
{
	cout << "HI this is Algo for first come" << endl;
	/*
	ReadyQueue->Dequeue_In_Variable(RunningProcess);

	while (RunningProcess->getCT() != 0 ) {

			runingTime++;
	}*/
}

void FirstComeProcessor::SetMAXW(int max)
{
	maxw = max;
}
bool FirstComeProcessor::IsThereKilled(int idOfProcess)
{
	LinkedList <Process*>* CopyOfReady = ReadyQueue;
	Process* Temp=  new Process;
	for (int i = 1; i <= countOfProcesses; i++)
	{
		CopyOfReady->returnkth(i);
		if (Temp->findProcess(idOfProcess)) {
			KilledOne = Temp;
			ReadyQueue->DeleteNode(Temp);
			return true;
		}
	}
	return false;
}
Process* FirstComeProcessor:: KillSignal()
{
	return KilledOne;
}



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
	ReadyQueue->InsertBeg(NewProcess);
}