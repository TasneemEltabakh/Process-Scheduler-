#include "FirstComeProcessor.h"



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
bool FirstComeProcessor::isthisProcessrEmpty()
{
	if (this->ReadyQueue.IsEmpty())
		return true;
}

void FirstComeProcessor::ScheduleAlgo()
{
	if (RunningProcess != nullptr)
	{
		if (RunningProcess->getCT() > 0)
		{
			RunningProcess->setCT(RunningProcess->getCT() - 1);
			timeforrequest++;
			expectedtime--;

			if (RunningProcess->getnIO() > 0 && timeforrequest == RunningProcess->seeTimeForAskForIO())
			{
				IORequest = new Process(*RunningProcess);
				timeforrequest = 0;
				expectedtime = expectedtime - RunningProcess->getCT();
				RunningProcess = nullptr;
				TerminatProcess = nullptr;
				return;
			}

			cout << "Step" << endl;
			return;
		}
		else
		{
			TerminatProcess = new Process(*RunningProcess);
			RunningProcess = nullptr;
			IORequest = nullptr;
			timeforrequest = 0;
			return;
		}
	}

	if (ReadyQueue.IsEmpty())
	{
		cout << "FCFS Ready Empty" << endl;
		TerminatProcess = nullptr;
		IORequest = nullptr;
		timeforrequest = 0;
		expectedtime = 0;
		return;
	}

	Process* nextProcess;
	ReadyQueue.Dequeue_In_Variable(nextProcess);

	RunningProcess = nextProcess;
	cout << "Enter new element" << endl;
	TerminatProcess = nullptr;
	IORequest = nullptr;
	return;

}
//	if (ReadyQueue.IsEmpty()) {
//		ProcessorState = IDLE;
//		return;
//	}
//	cout << "algo " << endl;
//
//	ProcessorState = busy;
//	ReadyQueue.Dequeue_In_Variable(RunningProcess);
//	//Here the previuse must go to TERM
//	ReadyQueue.Dequeue_In_Variable(RunningProcess);
//	RunningProcess->calcWT(wt);
//
//	for (int i = 1; i < RunningProcess->getCT(); i++) {
//
//		//runingTime++;
//		RunningProcess->setCT(RunningProcess->getCT() - 1);
//		//nada
//		if (RunningProcess->getCT() > 0 && RunningProcess->getRemainingCT() == RunningProcess->getCT() &&
//			rand() % 100 < forkprob) {
//			Process* child = new Process();
//			child->setCT(RunningProcess->getCT() - RunningProcess->getRemainingCT());
//			child->set_AT_Cild(RunningProcess->getAT());
//			countOfProcesses++; // ask is it like db or the file has the id ? or they did another thing 
//			child->setParent(RunningProcess);
//			RunningProcess->addChild(child);
//			ReadyQueue.InsertEnd(child);  // add process to the scheudlor ready queu  // ask for function to get the ready queue
//
//
//		}
//	}
//	
//	MoveMeToTerminal();
//		wt++;
//
//		if (ChcekMigration(RunningProcess))
//		{
//			cout << "process should migrate ";
//		}
//
//		else
//		{
//			wt = +(RunningProcess->getCT());
//			cout << " process moved to terminal";
//		}
//
//}

void FirstComeProcessor::SetMAXW(int max)
{
	maxw = max;
}
void FirstComeProcessor::IsThereKilled(int idOfProcess)
{
	if (!ReadyQueue.IsEmpty())
	{
		for (int i = 0; i < ReadyQueue.Count(); i++)
		{
			if (ReadyQueue.returnkth(i)->getPID() == idOfProcess)
			{
				if (ReadyQueue.returnkth(i)->MyChild() != nullptr)
				{
					IsThereKilled(ReadyQueue.returnkth(i)->MyChild()->getPID());
				}
				
				Process* process = new Process(*RunningProcess);
				Killedprocesses.enqueue(process);
				ReadyQueue.DeleteNodeindex(i);
				
			  
			}
		}
	}
	if (RunningProcess != nullptr) {

		if (RunningProcess->getPID() == idOfProcess)
		{


			if (RunningProcess->MyChild() != nullptr)
			{
				IsThereKilled(RunningProcess->MyChild()->getPID());
			}
	
			Process* process = new Process(*RunningProcess);
			Killedprocesses.enqueue(process);
			RunningProcess = nullptr;
			IORequest = nullptr;
			timeforrequest = 0;
			
		}

	}

	
}

void FirstComeProcessor::KillProcessAndChildren(Process* process)
{


	Process* child = process->MyChild();
	while (child != nullptr)
	{
		Process* nextChild = child->MyChild();
		KillProcessAndChildren(child);
		ReadyQueue.DeleteNode(child);
		delete child;
		child = nextChild;
	}
}

Process* FirstComeProcessor:: KillSignal()
{
	return KilledOne;
}
Process* FirstComeProcessor::MoveMeToTerminal()
{

	TerminatProcess = RunningProcess;
	return TerminatProcess;

}

void  FirstComeProcessor::AddToMyReadyList(Process& NewProcess)
{
	Process* newprocess = new Process(NewProcess);
	expectedtime = expectedtime + newprocess->getCT();
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
	return expectedtime;
}
Process* FirstComeProcessor::RemoveProcess()
{
	Process* StolenProcess = nullptr;
	if (!ReadyQueue.IsEmpty())
	{
		expectedtime = expectedtime - ReadyQueue.returnkth(ReadyQueue.Count() - 1)->getCT();
		ReadyQueue.Dequeue_In_Variable(StolenProcess);
		return StolenProcess;
	}
	
}

bool FirstComeProcessor::ChcekMigration(Process* running) {
	return false;
}
bool FirstComeProcessor::ISforked(int x)
{
	if (RunningProcess != nullptr && RunningProcess->getNumberChildren() == 0)
	{
		
	
		if (x < forkprob)
		{
			RunningProcess->setNumberChildren();
			return true;
		}
	}
	return false;
}
int FirstComeProcessor:: returnMyRunningCT()
{
	return RunningProcess->getCT();
}
void  FirstComeProcessor::SetToRunningChild(Process* child)
{
	RunningProcess->PointToMyChild(child);
}