#include "Process.h"

Process::Process() {

}

Process::Process(int x, int y, int z, int l) {

	PID = y; 
	AT = x;
	CT = z;
	nIO = l;
	iskilled = false;
}

Process::~Process() {

}

int Process::getPID() const {
	return PID;
}

int Process::getAT()const {
	return AT;
}

int Process::getCT() const {
	return CT;
}

int Process::getWT() const {
	return WT;
}

int Process::getRT() const {
	return RT;
}

int Process::getTRT() const {
	return TRT;
}

int Process::getTT() const {
	return TT;
}


void Process::calcWT() {
	WT = TRT - CT;
}


void Process::calcTRT() {
	TRT = TT - AT;
}


bool  Process::IsKilled()
{
	return iskilled;
}

void  Process::KillThisProcess()
{
	iskilled = true;
}


void Process::InsertToIOlist(int x, int y)
{
	IOpairs.enqueue(x);
	IOpairs.enqueue(y);

}