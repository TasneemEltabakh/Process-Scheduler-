#include "FirstComeProcessor.h"


//LinkedQueue<Process*> FirstComeProcessor::Killedprocesses;
FirstComeProcessor::FirstComeProcessor(int max, int fork)
{
	KilledOne = nullptr;
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
	if (!ReadyQueue.IsEmpty())
	{
		for (int i = 0; i < ReadyQueue.Count(); i++)
		{
			if (ReadyQueue.returnkth(i)->getPID() == idOfProcess)
			{
				KilledOne = ReadyQueue.returnkth(i);
				Killedprocesses.enqueue(KilledOne);
				// here i have to send it to terminal queue  ask ? if will need the terminal updetaed somewhere 
				TRMQueue.InsertEnd(KilledOne);
				ReadyQueue.DeleteNode(ReadyQueue.returnkth(i)); 
				return true;
			}
		}
	}
	//N
	if (!RunQueue.IsEmpty()) {
		
		for (int i = 0; i < RunQueue.Count(); i++) {
			if (RunQueue.returnkth(i)->getPID() == idOfProcess)
			{
				KilledOne = RunQueue.returnkth(i);
				Killedprocesses.enqueue(KilledOne);
				TRMQueue.InsertEnd(KilledOne);
				RunQueue.DeleteNode(RunQueue.returnkth(i));
				return true;
			}
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
	if (!ReadyQueue.IsEmpty()) AddToRun();
	return TerminatProcess;

}

void  FirstComeProcessor::AddToMyReadyList(Process& NewProcess)
{
	Process* newprocess = new Process(NewProcess);
	countOfProcesses++;
	ReadyQueue.InsertEnd(newprocess);
	
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
int FirstComeProcessor::getExpectedTime()
{
	LinkedList<Process*> copy(ReadyQueue);
	Process* process;
	while (!copy.IsEmpty())
	{
		copy.Dequeue_In_Variable(process);
		expectedtime += process->getCT();
	}
	return expectedtime;
}