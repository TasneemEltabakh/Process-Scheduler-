#include "FirstComeProcessor.h"


int FirstComeProcessor::countOfProcesses = 0;
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
	LinkedList <Process*> CopyOfReady = ReadyQueue;
	Process* Temp=  new Process;
	for (int i = 1; i <= countOfProcesses; i++)
	{
		CopyOfReady.returnkth(i);
		if (Temp->findProcess(idOfProcess)) {
			KilledOne = Temp;
			ReadyQueue.DeleteNode(Temp);
			return true;
		}
	}
	return false;
}
Process* FirstComeProcessor:: KillSignal()
{
	return KilledOne;
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
	//ReadyQueue->InsertBeg(NewProcess);
	cout << "HI this is Algo for first come" << endl;
	countOfProcesses++;
}
void FirstComeProcessor::AddToRun()
{
	/*ProcessorState = busy;
	RunningProcess = ReadyQueue.returnkth(0);
	ReadyQueue.DeleteFirst();
	cout << RunningProcess->getPID() << endl;*/

}
int FirstComeProcessor::getcount()
{
	return countOfProcesses;
}

