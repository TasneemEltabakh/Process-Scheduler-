#include "Process.h"

Process::Process() {

}

Process::Process(int x, int y, int z, int l,bool askforking) {

	PID = y; 
	AT = x;
	CT = z;
	nIO = l;
	iskilled = false;
	Isforking = askforking;  //R add

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

int Process::getrunt() const {
	return runningtime;
}
void Process::addruntime(int x) {
	runningtime += x;
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

void Process::SetFOrk() {  //R add
	Isforking = true;
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

void Process::setCT(int newCT) { //R add
	CT = newCT;
}

bool Process::checkforklist() {  //R add
	if (ForkedList.IsEmpty()) {
		return false;
	}
	else
		return true;
}
bool Process::IsForked() {  //R add
	return Isforking;
} 
void Process::setParentQueue(Process* Parent) {  //R add
	ParentQueue = Parent;
}
Process* Process::getParentQueue() {  //R add
	return ParentQueue;
}
Process* Process::getAllList() {  //R add 
	return ForkedList.Peek();
}


int Process::operator<< (const Process& c) const  //R add for UI
{
	return c.getPID();
}
}
bool Process:: findProcess(int i)
{
	bool Found = false;
	if (this->PID == i)
		return true;
	return false;
}