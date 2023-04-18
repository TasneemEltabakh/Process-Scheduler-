#include "RoundRobinProcessor.h"

RoundRobinProcessor::RoundRobinProcessor(int sliceTime, int RTF) {

	this->sliceTime = sliceTime;
	this->RTF = RTF;
}

RoundRobinProcessor::~RoundRobinProcessor(){}

void RoundRobinProcessor::ScheduleAlgo()
{
	if (ReadyQueue.IsEmpty()) {
		return ;
	}

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
}

void RoundRobinProcessor::SetRTF(int rt) {
	RTF = rt;

}