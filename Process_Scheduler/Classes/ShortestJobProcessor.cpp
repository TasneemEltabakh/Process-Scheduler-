#include "ShortestJobProcessor.h"


ShortestJobProcessor::ShortestJobProcessor()
{
	countOfProcesses = 0;
}

ShortestJobProcessor::~ShortestJobProcessor()
{
}

void ShortestJobProcessor::ScheduleAlgo()
{
	TerminatProcess = nullptr;
	IORequest = nullptr;
	//New Start
	if (RunningProcess != nullptr) {
		if (RunningProcess->getCT() != 0) {
			RunningProcess->setCT(RunningProcess->getCT() - 1);
			expectedtime = expectedtime - 1;
			if (RunningProcess->getnIO()!=0) {
				if (currentTime == RunningProcess->seeTimeForAskForIO()) {
					IORequest = new Process(*RunningProcess);  //Flag gor I/O
				}
			}
			cout << "step" << endl;
			return;
		}
		else {
			TerminatProcess = new Process(*RunningProcess);  //Flag For Term
			if (!ReadyQueue.IsEmpty()) {
				ReadyQueue.Dequeue_In_Variable(RunningProcess);
				cout << "enter new elemnt" << endl;
				return;
			}
		}
	}
	if (ReadyQueue.IsEmpty()) {
		cout << "SJP Ready Empty" << endl;
		return;
	}
	if (RunningProcess==nullptr) {
		if (ReadyQueue.IsEmpty()) {
			cout << "SJP Ready Empty2" << endl;
			return;
		}
		else {
			ReadyQueue.Dequeue_In_Variable(RunningProcess);
			cout << "enter new elemnt" << endl;
			return;
		}
	}
}
void ShortestJobProcessor::AddToMyReadyList(Process& NewProcess)
{
	Process* newprocess = new Process(NewProcess);
	countOfProcesses++;

	expectedtime = expectedtime + newprocess->getCT();
	ReadyQueue.enqueue(newprocess);

}
void ShortestJobProcessor::AddToRun()
{
	ProcessorState = busy;
	if (ReadyQueue.IsEmpty()) {
		return;
	}

	ReadyQueue.Dequeue_In_Variable(RunningProcess);
	downtimer = RunningProcess->getCT();
}

Process* ShortestJobProcessor::getkth(int k)
{
	return ReadyQueue.returnkth(k);
}
Process* ShortestJobProcessor::MoveMeToTerminal()
{
	TerminatProcess = RunningProcess;
	RunningIsFree();
	if (!ReadyQueue.IsEmpty()) AddToRun();
	return TerminatProcess;
}
bool ShortestJobProcessor::CheckIfemptyready()
{
	if (ReadyQueue.IsEmpty())
		return true;
	return false;

}
int ShortestJobProcessor::getExpectedTime()
{
	return expectedtime;
}
int ShortestJobProcessor::getcount()
{
	return ReadyQueue.Count();
}
Process* ShortestJobProcessor::RemoveProcess()
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