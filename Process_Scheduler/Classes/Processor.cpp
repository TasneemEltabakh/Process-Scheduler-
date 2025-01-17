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
	getRunningCt = 0;
	RunningProcess = new Process;
	TerminatProcess = nullptr;
	IORequest = nullptr;
	timeforrequest = 0;
	
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
bool  Processor::StoppedCheck()
{
	if (this->ProcessorState == Stop)
		return true;
	else
	return false;
}
void  Processor::OutOfService(int n)
{
	ProcessorState = Stop;
	breaktime = n;
}
void Processor::BacktoService()
{
	ProcessorState = IDLE;
	breaktime = 0;
}
int Processor::CountDownBreak()
{
	breaktime--;
	return breaktime;
}
Process* Processor::getIO()
{
	return IORequest;
}
Process* Processor::getTerminal()
{
	return TerminatProcess;
}



