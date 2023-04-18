#include "RoundRobinProcessor.h"

RoundRobinProcessor::RoundRobinProcessor(int sliceTime, int RTF) {

	this->sliceTime = sliceTime;
	this->RTF = RTF;
}

RoundRobinProcessor::~RoundRobinProcessor(){}

Process* RoundRobinProcessor::ScheduleAlgo()
{
	if (ReadyQueue.isEmpty()) {
		return ;
	}

	for (int i = 0; ReadyQueue.isEmpty() ; i + sliceTime) {

		if (RunningProcess != nullptr) 
		{
			if (RunningProcess->getrunt() < RunningProcess->getCT()) {
				ReadyQueue.enqueue(RunningProcess);
			}
			sch->moveToTrm(RunningProcess);
		}

		ReadyQueue.dequeue(RunningProcess);
		RunningProcess->addruntime(sliceTime);
	}
}

void RoundRobinProcessor::SetRTF(int rt) {
	RTF = rt;

}