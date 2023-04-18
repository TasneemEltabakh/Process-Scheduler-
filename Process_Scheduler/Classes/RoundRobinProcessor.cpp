#include "RoundRobinProcessor.h"

RoundRobinProcessor::RoundRobinProcessor(int sliceTime, int RTF) {

	this->sliceTime = sliceTime;
	this->RTF = RTF;
}
RoundRobinProcessor::RoundRobinProcessor() {}

RoundRobinProcessor::~RoundRobinProcessor(){}

void RoundRobinProcessor::ScheduleAlgo()
{
	if (ReadyQueue.IsEmpty()) {
		return ;
	}
	/*Process* current, c2;

	for (int i = 0; ReadyQueue.IsEmpty() ; i + sliceTime) {

		if (RunningProcess != nullptr) 
		{
			if (RunningProcess->getrunt() < RunningProcess->getCT()) {
				ReadyQueue.enqueue(RunningProcess);
			}
			sch->moveToTrm(RunningProcess);
		}

		ReadyQueue.Dequeue_In_Variable(RunningProcess);
		RunningProcess->addruntime(sliceTime);
	}
	}*/
	cout << "HI this is Algo for round " << endl;
}

void RoundRobinProcessor::SetRTF(int rt) {
	RTF = rt;

}
void RoundRobinProcessor::AddToMyReadyList(Process* NewProcess)
{
	//ReadyQueue->enqueue(NewProcess);
	cout << "HI this is Algo for round " << endl;
}