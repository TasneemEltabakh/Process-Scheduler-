#include "RoundRobinProcessor.h"


RoundRobinProcessor::RoundRobinProcessor(int sliceTime, int RTF) {

	this->sliceTime = sliceTime;
	this->RTF = RTF;
	countOfProcesses = 0;
}

RoundRobinProcessor::~RoundRobinProcessor(){}
void RoundRobinProcessor::ScheduleAlgo()
{	
	//New Start



	/*if (ReadyQueue.IsEmpty()) {
		cout << "RR Ready list is empty" << endl;

	}
	else if (RunningProcess == nullptr && !ReadyQueue.IsEmpty()) {
		ReadyQueue.Dequeue_In_Variable(RunningProcess);   //First elemnt to enter
		InternalsliceTime = getsliceTime();       //start new count for 
		cout << "RR enter first element " << endl;
	}
	else if (InternalsliceTime==0) {
		ReadyQueue.enqueue(RunningProcess);
		cout << " slecetime= " << RunningProcess->getCT() << endl;
		cout << "RR time finish for this process" << endl;
		ReadyQueue.Dequeue_In_Variable(RunningProcess);
		cout << "RR enter new element" << endl;
		InternalsliceTime = getsliceTime();       //start new count for
	}
	else if (RunningProcess != nullptr && RunningProcess->getCT() != 0 && InternalsliceTime != 0) {
		if (currentTime == RunningProcess->seeTimeForAskForIO()) {  //Check every time if request I/O
			RunningProcess->setaskedforOI(true);  //flag for I/O Request
			cout << "RR flag ask for IO" << endl;
		}
		InternalsliceTime = InternalsliceTime - 1;
		RunningProcess->setCT(RunningProcess->getCT() - 1);   //Step
		cout << "RR step" << endl;
		expectedtime = expectedtime - 1;  //for T
	}
	else if (RunningProcess != nullptr &&  RunningProcess->getCT() == 0) {  //The process in RUN finished --> So get the next
		RunningProcess->setIsFinshed(true);  //flag for termnate
		cout << "RR element finish, go to termnal" << endl;
		if (ReadyQueue.IsEmpty()) {  //The Ready list Finished
			cout << "RR Ready List is Empty" << endl;
			return;
		}

		ReadyQueue.Dequeue_In_Variable(RunningProcess);
		InternalsliceTime = getsliceTime();   //start new count for 
	}	
	else {
		return;
	}*/
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
bool RoundRobinProcessor::isthisProcessrEmpty()
{
	if (this->ReadyQueue.IsEmpty())
		return true;
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