#include "ShortestJobProcessor.h"

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
}