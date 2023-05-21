#include "Process.h"

Process::Process() {
	PID = 0;
	AT = 0;
	CT = 0;
	nIO = 0;
	iskilled = false;
	
}

Process::Process(int x, int y, int z, int l) {

	PID = y; 
	AT = x;
	CT = z;
	nIO = l;
	iskilled = false;
	duration = 0;
}
Process::Process(const Process& other)
{
	
	PID = other.PID;
	AT = other.AT;
	CT = other.CT;
	nIO = other.nIO;
	iskilled = other.iskilled;
	IOpairs = other.IOpairs; 

	
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

void Process::calcWT(int w) {
	WT = +w;
}


void Process::calcTRT() {
	TRT = WT + CT;
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


  ////////////////////////////////////////////////////////
 //                      I/O                    /////////
////////////////////////////////////////////////////////
void  Process::addDatatoIOPairs(int x, int y)  //edit fom T
{
	IOpairs.x = x;
	IOpairs.y = y;

	IOpairs.pairs.enqueue(make_pair(x, y));

}
//Phase Two
int Process::seeTimeForAskForIO() {  //R add for algo SJP
	int xValue = IOpairs.x;
	int yValue = IOpairs.y;
	pair<int, int> pairsValue = IOpairs.pairs.Peek();
	return pairsValue.first;
}
 void Process::seeDurationForAskForIO() { //R add for algo SJP

	int xValue = IOpairs.x;
	int yValue = IOpairs.y;
	pair<int, int> pairsValue = IOpairs.pairs.Peek();
	duration = pairsValue.second;
	
	
}


void  Process::downDuration()
{
	duration--;
}
int Process::get_duration()
{
	return duration;
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

bool Process:: findProcess(int i)
{
	bool Found = false;
	if (this->PID == i)
		return true;
	return false;
}

int Process::getnIO() {  //R add2
	return nIO;
}
// nada for fork 
void Process::setParent(Process* parent) {
	Parent = parent;
}

void Process::addChild(Process* child) {
	Children.enqueue(child);
}

LinkedQueue<Process*>& Process::getchildren() {
	return Children;
}
int Process::getRemainingCT() {
	return RemainingCT;
}
void Process::set_AT_Cild(int newAT) { 
	childAT = newAT;
}