#include "Process.h"\

Process::Process() {

}

Process::Process(int x, int y, int z, int l) {
	PID = x; AT = y; CT = z;  IO = l;
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

}

void Process::setIO(int x) {
	IO = x;
}

void Process::setCT(int x) {
	CT = x;
}

void Process::calcWT() {
	WT = TRT - CT;
}

void Process::setRT(int x) {
	RT = x;
}

void Process::calcTRT() {
	TRT = TT - AT;
}

void Process::setTT(int x) {
	TT = x;
}

bool Process::RRmigration(int RTF) {
	if (RT < RTF)
		return true;
	else
		return false;
}

bool Process::FCFSmigration(int MaxW) {
	if (WT > MaxW)
		return true;
	else
		return false;
}
