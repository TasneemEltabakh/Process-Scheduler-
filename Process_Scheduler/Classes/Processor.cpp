#include "Processor.h"
#include "..//Supplementary.h"

Processor::Processor()
{
	ProcessorState = IDLE;
	load = 0;
	utilization = 0;
}

Processor::~Processor(){
	
}

Process* Processor:: MoveMeToTerminal()
{
	return RunningProcess;
}
bool Processor::IsIDlE() const
{
	if (ProcessorState == IDLE)
		return true;
	return false;

}
Process* Processor::RunningNow()
{
	return RunningProcess;
}
void Processor:: RunningIsFree()
{
	RunningProcess = nullptr;
	ProcessorState = IDLE;
}

