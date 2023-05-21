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
	expectedtime = 0;
	RunningProcess = new Process;
	TerminatProcess = nullptr;
	IORequest = nullptr;
}

Processor::~Processor(){
	
}

void Processor::CurrentTime(int time)
{
	this->currentTime = time;

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
	RunningProcess->setCT(RunningProcess->getCT() - 1);
	return RunningProcess;
}
void Processor:: RunningIsFree()
{
	cout << "Iam Now a free running processor " << endl;
	ProcessorState = IDLE;
	RunningProcess = nullptr;

}
int Processor::getId()
{
	return Id;
}


