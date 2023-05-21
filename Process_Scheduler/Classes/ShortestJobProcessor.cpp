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

	while (ReadyQueue.Count() !=0) {

			ReadyQueue.Dequeue_In_Variable(RunningProcess);
			while (RunningProcess->getCT()!=0) {
				RunningProcess->setCT(RunningProcess->getCT() - 1);
			}
			
	}
	if (ReadyQueue.IsEmpty()) {
		cout << "The Ready List is Empty" << endl;
	}

	
}
void ShortestJobProcessor::AddToMyReadyList(Process& NewProcess)
{
	Process* newprocess = new Process(NewProcess);
	countOfProcesses++;
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
int ShortestJobProcessor::getcount()
{
	return ReadyQueue.Count();
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
	PriorityQueue<Process*> copy(ReadyQueue);
	Process* process;
	while (!copy.IsEmpty())
	{
		copy.Dequeue_In_Variable(process);
		expectedtime += process->getCT();
	}
	return expectedtime;
}