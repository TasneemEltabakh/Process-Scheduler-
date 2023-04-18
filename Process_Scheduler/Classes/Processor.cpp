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
	RunningProcess = nullptr;
	TerminatProcess = nullptr;
}

Processor::~Processor(){
	
}


bool Processor::IsIDlE() const
{
	if (ProcessorState == IDLE)
		return true;
	return false;

}
bool Processor::CheckIfRun() {  //R add
	if (RunningProcess==nullptr) {
		return false;
	}
	return true;
}
Process* Processor::RunningNow()
{
	downtimer--;
	RunningProcess->setCT(downtimer);
	return RunningProcess;
}
void Processor:: RunningIsFree()
{
	cout << "Iam Now a free running processor " << endl;
	RunningProcess = nullptr;
	ProcessorState = IDLE;
}
int Processor::getId()
{
	return Id;
}

