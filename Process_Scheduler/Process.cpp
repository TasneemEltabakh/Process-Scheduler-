#include "Process.h"

Process::Process() {
	//PID = 0;
	//AT = 0;
	//CT = 0;
	//nIO = 0;
	iskilled = false;
	duration = 0;
	CTstepn = CT;  //for UI
	
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
	TT = other.TT;  //for UI
	IO_D = other.IO_D;  //for UI
	TRT = other.TT - other.AT;  //for UI
	WT = TRT - other.CT;  //for UI
	RTAfterSum = other.AT - other.RT;  //for UI
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
void Process::addDatatoIOPairs(int x, int y)
{
	IOpairs.enqueue(x);
	IOpairs.enqueue(y);
}

//Phase Two
int Process::seeTimeForAskForIO() {  //R add for algo SJP

	return IOpairs.Peek();
}
void Process::seeDurationForAskForIO()
{
	if (duration == 0 && IOpairs.IsEmpty()!= true)
	{
		int x;
		IOpairs.Dequeue_In_Variable(x);
		IOpairs.Dequeue_In_Variable(x);
		nIO--;
		duration = x;
		cout << "duration is " << x << endl;
		dequeueIO();
	}
	else
		return;
}
void Process::setdurationtozero() {
	duration = 0;
}

void  Process::downDuration()
{
	duration = duration - 1;
	cout << "duration is " << duration << endl;
}
int Process::get_duration()
{
	cout << "duration is in the getting" << duration << endl;

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
void Process:: dequeueIO()
{

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

void Process::setTT(int newTT) {  //for UI
	TT = newTT;
}
void Process::stCTstepn(int newTT) {  //for UI
	CTstepn = newTT;
}
int Process::getCTstepn() {  //for UI
	return CTstepn;
}
void Process::setIO_D(int newIO_D) {  //for UI
	IO_D = IO_D + newIO_D;
}
int Process::getIO_D() {  //for UI
	return IO_D;
}
void Process::setRT(int newRT) {  //for UI
	RT = newRT;
}
int Process::getRTAfterSum() {  //for UI
	return RTAfterSum;
}