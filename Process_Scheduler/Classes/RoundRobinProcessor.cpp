#include "RoundRobinProcessor.h"

RoundRobinProcessor::RoundRobinProcessor(int sliceTime, int RTF) {

	this->sliceTime = sliceTime;
	this->RTF = RTF;
}

RoundRobinProcessor::~RoundRobinProcessor(){}
void RoundRobinProcessor::ScheduleAlgo()
{

}

void RoundRobinProcessor::SetRTF(int rt) {
	RTF = rt;

}