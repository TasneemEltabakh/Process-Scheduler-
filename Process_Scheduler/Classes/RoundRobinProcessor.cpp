#include "RoundRobinProcessor.h"


RoundRobinProcessor::RoundRobinProcessor(int sliceTime, int RTF) {

	this->sliceTime = sliceTime;
	this->RTF = RTF;
	InternalsliceTime = sliceTime;  //R add2
	countOfProcesses = 0;
}

RoundRobinProcessor::~RoundRobinProcessor(){}
void RoundRobinProcessor::ScheduleAlgo()
{	
	//New Start
	TerminatProcess = nullptr;
	IORequest = nullptr;
	//New Start
	if (RunningProcess != nullptr) {
		if (InternalsliceTime==0) {
			ReadyQueue.enqueue(RunningProcess);
			ReadyQueue.Dequeue_In_Variable(RunningProcess);
			setInternalsliceTime(sliceTime);  //Restart the sliceTime
			cout << "RR sliceTime, enter new elemnt" << endl;
			return;
		}
		if (RunningProcess->getCT() != 0) {
			RunningProcess->setCT(RunningProcess->getCT() - 1);
			expectedtime = expectedtime - 1;
			InternalsliceTime = InternalsliceTime - 1;
			if (RunningProcess->getnIO() != 0) {
				if (currentTime == RunningProcess->seeTimeForAskForIO()) {
					IORequest = new Process(*RunningProcess);  //Flag gor I/O
					cout << "RR requist I/O" << endl;
				}
			}
			cout << "RR step" << endl;
			return;
		}
		else {
			TerminatProcess = new Process(*RunningProcess);  //Flag For Term
			cout << "RR Termnal" << endl;
			if (!ReadyQueue.IsEmpty()) {
				ReadyQueue.Dequeue_In_Variable(RunningProcess);
				setInternalsliceTime(sliceTime);  //Restart the sliceTime
				cout << "RR enter new elemnt" << endl;
				return;
			}
		}
	}
	if (ReadyQueue.IsEmpty()) {
		cout << "RR Ready Empty" << endl;
		return;
	}
	else {
		ReadyQueue.Dequeue_In_Variable(RunningProcess);
		setInternalsliceTime(sliceTime);  //Restart the sliceTime
		cout << "RR enter new elemnt" << endl;
		return;
	}
}
int RoundRobinProcessor::getsliceTime() {
	return sliceTime;
}
void RoundRobinProcessor::setInternalsliceTime(int newtime) {
	InternalsliceTime = newtime;
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