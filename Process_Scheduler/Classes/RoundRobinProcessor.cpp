#include "RoundRobinProcessor.h"

RoundRobinProcessor::RoundRobinProcessor(int sliceTime, int RTF) {

	this->sliceTime = sliceTime;
	this->RTF = RTF;
}

RoundRobinProcessor::~RoundRobinProcessor(){}
void RoundRobinProcessor::ScheduleAlgo()
{
	Process* current, c2;

	for (int i = 0; i < (sliceTime * countOfProcesses); i + sliceTime) {
		if(RunningProcess != nullptr)
			ReadyQueue->enqueue(RunningProcess);

		ReadyQueue->dequeue(current);
		RunningProcess = current;

	}
}

void RoundRobinProcessor::SetRTF(int rt) {
	RTF = rt;

}