#include "ShortestJobProcessor.h"

ShortestJobProcessor::ShortestJobProcessor()
{
}

ShortestJobProcessor::~ShortestJobProcessor()
{
}

void ShortestJobProcessor::ScheduleAlgo()
{
	cout << "HI this is Algo for shortest " << endl;
}
void ShortestJobProcessor::AddToMyReadyList(Process* NewProcess)
{
	ReadyQueue->enqueue(NewProcess);
	cout << "HI this is Algo for shortest " << endl;
}
void ShortestJobProcessor::AddToRun()
{
	ProcessorState = busy;
	if (ReadyQueue->IsEmpty()) {
		return;
	}

	ReadyQueue->Dequeue_In_Variable(RunningProcess);
	cout << RunningProcess->getPID() << endl;
}