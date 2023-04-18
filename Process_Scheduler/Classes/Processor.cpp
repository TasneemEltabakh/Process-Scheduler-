#include "Processor.h"
#include "..//Supplementary.h"
int Processor:: Count=0;
Processor::Processor()
{
	Count++;
	ProcessorState = IDLE;
	load = 0;
	utilization = 0;
	Id = Count;
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
int Processor::getId()
{
	return Id;
}


