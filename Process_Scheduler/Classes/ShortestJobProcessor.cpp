#include "ShortestJobProcessor.h"

int ShortestJobProcessor::countOfProcesses = 0;
ShortestJobProcessor::ShortestJobProcessor()
{

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
			//Here the previuse must go to TERM
	}
	if (ReadyQueue.IsEmpty()) {
		cout << "The Ready List is Empty" << endl;
	}

	//cout << "HI this is Algo for shortest " << endl;
}
void ShortestJobProcessor::AddToMyReadyList(Process* NewProcess)
{
	ReadyQueue.enqueue(NewProcess);
	cout << "HI this is Algo for shortest " << endl;
	//countOfProcesses++;
}
void ShortestJobProcessor::AddToRun()
{
	/*ProcessorState = busy;
	if (ReadyQueue->IsEmpty()) {
		return;
	}

	ReadyQueue->Dequeue_In_Variable(RunningProcess);
	cout << RunningProcess->getPID() << endl;*/
}
int ShortestJobProcessor::getcount()
{
	return countOfProcesses;
}
