#include "RoundRobinProcessor.h"


RoundRobinProcessor::RoundRobinProcessor(int sliceTime, int RTF) {

	this->sliceTime = sliceTime;
	this->RTF = RTF;
	countOfProcesses = 0;
}

RoundRobinProcessor::~RoundRobinProcessor(){}
void RoundRobinProcessor::ScheduleAlgo()
{	
	if (RunningProcess == nullptr && !ReadyQueue.IsEmpty()) {
		ReadyQueue.Dequeue_In_Variable(RunningProcess);   //First elemnt to enter
		InternalsliceTime = getsliceTime();       //start new count for 

	}
	else if (InternalsliceTime==0) {
		ReadyQueue.enqueue(RunningProcess);
		ReadyQueue.Dequeue_In_Variable(RunningProcess);
		InternalsliceTime = getsliceTime();       //start new count for
	}
	else if (RunningProcess->getCT() == 0) {  //The process in RUN finished --> So get the next
		RunningProcess->setIsFinshed(true);  //flag for termnate
		cout << "element finish" << endl;
		if (ReadyQueue.IsEmpty()) {  //The Ready list Finished
			cout << "The Ready List is Empty" << endl;
			return;
		}

		ReadyQueue.Dequeue_In_Variable(RunningProcess);
		InternalsliceTime = getsliceTime();   //start new count for 
	}
	else if (RunningProcess != nullptr && RunningProcess->getCT()!=0 && InternalsliceTime !=0) {
		if (currentTime == RunningProcess->seeTimeForAskForIO()) {  //Check every time if request I/O
			RunningProcess->setaskedforOI(true);  //flag for I/O Request
		}
		InternalsliceTime = InternalsliceTime - 1;
		RunningProcess->setCT(RunningProcess->getCT() - 1);   //Step
		expectedtime = expectedtime - 1;  //for T
	}
	//R work on phase one
	/*for (int i = 0; i < (sliceTime * countOfProcesses); i + sliceTime) {
		if (ReadyQueue.IsEmpty()) {
			cout << "The Ready List is Empty" << endl;
			return;
		}
		else if (!ReadyQueue.IsEmpty() && RunningProcess == nullptr) {
			ReadyQueue.Dequeue_In_Variable(RunningProcess);
		}
		else {
			//Process* newProcess = new Process;
			//newProcess = RunningProcess;
			ReadyQueue.enqueue(RunningProcess);
			ReadyQueue.Dequeue_In_Variable(RunningProcess);
		}

		//for (int j = 0; j < sliceTime; j++) {
		//	if (RunningProcess->getCT() == 0) {
		//		                              //Here the previuse must go to TERM
		//	}
		//}

		if (RunningProcess->getCT() <= sliceTime) {
			for (int j = 0; j < sliceTime; j++) {
				if (RunningProcess->getCT() == 0) {
					//Here the previuse must go to TERM
				}
				else {
					RunningProcess->setCT(RunningProcess->getCT() - 1);
				}
			}
		}
		else {
			RunningProcess->setCT(RunningProcess->getCT() - sliceTime);
		}

	}
	//cout << "HI this is Algo for round " << endl;*/


	/*Process* current, c2;   //Ariam Work

	for (int i = 0; i < (sliceTime * countOfProcesses); i + sliceTime) {
		if(RunningProcess != nullptr)
			ReadyQueue->enqueue(RunningProcess);

		ReadyQueue->Dequeue_In_Variable(current);
		RunningProcess = current;

	}*/

	//if (ReadyQueue.IsEmpty()) {

	//}
	//else if (!ReadyQueue.IsEmpty() && RunningProcess == nullptr) {
	//	ReadyQueue.Dequeue_In_Variable(RunningProcess);
	//}
	//else {
	//	for (int i = 0; i < (sliceTime * countOfProcesses); i + sliceTime) {
	//			ReadyQueue.enqueue(RunningProcess);
	//			ReadyQueue.Dequeue_In_Variable(RunningProcess);

	//	}
	//}
	//
	////Process* current, c2;
	//
}
int RoundRobinProcessor::getsliceTime() {
	return sliceTime;
}
void RoundRobinProcessor::setsliceTime(int newtime) {
	sliceTime = newtime;
}


void RoundRobinProcessor::SetRTF(int rt) {
	RTF = rt;

}


void RoundRobinProcessor::AddToMyReadyList(Process& NewProcess)
{
	Process* newprocess = new Process(NewProcess);
	countOfProcesses++;

	expectedtime = expectedtime + newprocess->getCT();
	ReadyQueue.enqueue(newprocess);
	


}
void RoundRobinProcessor::AddToRun()
{
	ProcessorState = busy;
	if (ReadyQueue.IsEmpty()) {
		return;
	}
	
	ReadyQueue.Dequeue_In_Variable(RunningProcess);
	downtimer = RunningProcess->getCT();
}
int RoundRobinProcessor::getcount()
{
	return ReadyQueue.Count();
}
Process* RoundRobinProcessor::getkth(int k)
{
	return ReadyQueue.returnkth(k);
}

Process* RoundRobinProcessor::MoveMeToTerminal()
{
	TerminatProcess = RunningProcess;
	RunningIsFree();
	if (!ReadyQueue.IsEmpty()) AddToRun();
	return TerminatProcess;
}
bool RoundRobinProcessor::CheckIfemptyready()
{
	if (ReadyQueue.IsEmpty())
		return true;
	return false;
}
int RoundRobinProcessor::getExpectedTime()
{
	return expectedtime;

}
Process* RoundRobinProcessor::RemoveProcess()
{
	Process* StolenProcess = nullptr;

	if (!ReadyQueue.IsEmpty())
	{
		StolenProcess = new Process(*ReadyQueue.returnkth(ReadyQueue.Count() - 1));
		expectedtime = expectedtime - ReadyQueue.returnkth(ReadyQueue.Count() - 1)->getCT();
		ReadyQueue.DeleteNodePlace(ReadyQueue.Count() - 1);
	}
	return StolenProcess;
}