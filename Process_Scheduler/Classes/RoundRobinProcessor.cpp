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
	TerminatProcess = nullptr;
	IORequest = nullptr;


	if (RunningProcess != nullptr)
	{
		if (RunningProcess->getCT() > 0)
		{
			if (InternalsliceTime == 0) {
				ReadyQueue.enqueue(RunningProcess);
				ReadyQueue.Dequeue_In_Variable(RunningProcess);
				setInternalsliceTime(sliceTime);  //Restart the sliceTime
				cout << "RR sliceTime, enter new elemnt" << endl;
				return;
			}

			RunningProcess->setCT(RunningProcess->getCT() - 1);
			expectedtime--;
			InternalsliceTime = InternalsliceTime - 1;


			if (RunningProcess->getnIO() > 0 && currentTime == RunningProcess->seeTimeForAskForIO())
			{
				IORequest = new Process(*RunningProcess);
			}

			cout << "Step" << endl;
			return;
		}
		else
		{
			TerminatProcess = new Process(*RunningProcess);
			RunningProcess = nullptr;
		}
	}


	if (ReadyQueue.IsEmpty())
	{
		cout << "SJP Ready Empty" << endl;
		return;
	}


	Process* shortestJob = ReadyQueue.Peek();
	ReadyQueue.Dequeue_In_Variable(shortestJob);
	setInternalsliceTime(sliceTime);  //Restart the sliceTime
	RunningProcess = shortestJob;
	cout << "Enter new element" << endl;

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