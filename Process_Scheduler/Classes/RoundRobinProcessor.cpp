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
		if (RunningProcess->getCTstepn() > 0)
		{
			

			if (InternalsliceTime == 0) {
				ReadyQueue.enqueue(RunningProcess);
				ReadyQueue.Dequeue_In_Variable(RunningProcess);
				setInternalsliceTime(sliceTime);  //Restart the sliceTime
				cout << "RR sliceTime, enter new elemnt" << endl;
				return;
			}

			RunningProcess->stCTstepn(RunningProcess->getCTstepn() - 1);
			expectedtime--;
			timeforrequest++;
			InternalsliceTime = InternalsliceTime - 1;


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
			RunningProcess->setTT(currentTime);  //forUI
			TerminatProcess = new Process(*RunningProcess);
			RunningProcess = nullptr;
			timeforrequest = 0;
		}
	}


	if (ReadyQueue.IsEmpty())
	{
		cout << "SJP Ready Empty" << endl;
		timeforrequest = 0;
		expectedtime = 0;
		return;
	}


	Process* shortestJob = ReadyQueue.Peek();
	ReadyQueue.Dequeue_In_Variable(shortestJob);
	setInternalsliceTime(sliceTime);  //Restart the sliceTime
	RunningProcess = shortestJob;
	RunningProcess->stCTstepn(RunningProcess->getCT());
	RunningProcess->setRT(currentTime);  //for UI
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