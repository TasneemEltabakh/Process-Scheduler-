#include "FirstComeProcessor.h"

FirstComeProcessor::FirstComeProcessor()
{

}
FirstComeProcessor::~FirstComeProcessor()
{

}
void FirstComeProcessor::ScheduleAlgo()
{
	Process current;
	for (int i = 0; i < countOfProcesses; i++) {
		ReadyQueue->dequeue(current);
		Runing->enqueue(current);
	};
}
void  FirstComeProcessor::SetMAXW(int maxw)
{
	Maxw = maxw;
}
void FirstComeProcessor::Forking() {
	int random = 1 + (rand() % 100);
	if (random <= Forkprob) {
		Scheduler* sch = new Scheduler();
		cout << "call schedular to fork a process" << endl;
		delete sch;
	};
}