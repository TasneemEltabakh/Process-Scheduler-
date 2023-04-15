#include "RoundRobinProcessor.h"

void RoundRobinProcessor::SetSLICETIME(int slice_Time) {
	sliceTime = slice_Time;

}
RoundRobinProcessor::RoundRobinProcessor() {}
RoundRobinProcessor::~RoundRobinProcessor(){}
void RoundRobinProcessor::ScheduleAlgo()
{
	Process current, c2;
	for (int i = 0; i < (sliceTime * countOfProcesses); i + sliceTime) {
		ReadyQueue->dequeue(current);
		Runing->dequeue(c2);
		Runing->enqueue(current);
		ReadyQueue->enqueue(c2);
		
	}
}

void RoundRobinProcessor::SetRTF(int rt) {
	RTF = rt;

}