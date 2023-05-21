#include "ShortestJobProcessor.h"


ShortestJobProcessor::ShortestJobProcessor()
{
	countOfProcesses = 0;
}

ShortestJobProcessor::~ShortestJobProcessor()
{
}

void ShortestJobProcessor::ScheduleAlgo()
{
	////Before Understand The logic of Time
	//*while (ReadyQueue.Count() != 0) {
	//		ReadyQueue.Dequeue_In_Variable(RunningProcess);
	//		while (RunningProcess->getCT()!=0) {
	//			RunningProcess->setCT(RunningProcess->getCT() - 1);
	//		}
	//}
	//if (ReadyQueue.IsEmpty()) {
	//	cout << "The Ready List is Empty" << endl;
	//}*/
	//if (RunningProcess==nullptr && !ReadyQueue.IsEmpty()) {  //The first Process in RUN
	//	ReadyQueue.Dequeue_In_Variable(RunningProcess);
	//	cout << "enter first element "<<endl;
	//}
	//else if (RunningProcess->getCT() == 0) {  //The process in RUN finished --> So get the next
	//	RunningProcess->setIsFinshed(true);  //flag for termnate
	//	cout << "element finish" << endl;
	//	if (ReadyQueue.IsEmpty()) {  //The Ready list Finished
	//		cout << "The Ready List is Empty" << endl;
	//		return;
	//	}

	//	ReadyQueue.Dequeue_In_Variable(RunningProcess);   
	//}
	//else if (RunningProcess!=nullptr && RunningProcess->getCT() != 0) {  //Once it has process in RUN and not finished yet
	//	if (currentTime == RunningProcess->seeTimeForAskForIO()) {  //Check every time if request I/O
	//		RunningProcess->setaskedforOI(true);  //flag for I/O Request
	//	}
	//	RunningProcess->setCT(RunningProcess->getCT() - 1);   //Step
	//	expectedtime = expectedtime - 1;  //for T
	//	cout << "step" << endl;
	//}
}
void ShortestJobProcessor::AddToMyReadyList(Process& NewProcess)
{
	Process* newprocess = new Process(NewProcess);
	countOfProcesses++;

	expectedtime = expectedtime + newprocess->getCT();
	ReadyQueue.enqueue(newprocess);

}
void ShortestJobProcessor::AddToRun()
{
	ProcessorState = busy;
	if (ReadyQueue.IsEmpty()) {
		return;
	}

	ReadyQueue.Dequeue_In_Variable(RunningProcess);
	downtimer = RunningProcess->getCT();
}

Process* ShortestJobProcessor::getkth(int k)
{
	return ReadyQueue.returnkth(k);
}
Process* ShortestJobProcessor::MoveMeToTerminal()
{
	TerminatProcess = RunningProcess;
	RunningIsFree();
	if (!ReadyQueue.IsEmpty()) AddToRun();
	return TerminatProcess;
}
bool ShortestJobProcessor::CheckIfemptyready()
{
	if (ReadyQueue.IsEmpty())
		return true;
	return false;

}
int ShortestJobProcessor::getExpectedTime()
{
	return expectedtime;
}
int ShortestJobProcessor::getcount()
{
	return ReadyQueue.Count();
}
Process* ShortestJobProcessor::RemoveProcess()
{
	Process* StolenProcess = nullptr;
	if (!ReadyQueue.IsEmpty())
	{
		expectedtime = expectedtime - ReadyQueue.returnkth(ReadyQueue.Count() - 1)->getCT();
		ReadyQueue.Dequeue_In_Variable(StolenProcess);
	}
	return StolenProcess;
}