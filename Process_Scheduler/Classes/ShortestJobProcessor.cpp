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
	

    if (RunningProcess != nullptr)
    {
        if (RunningProcess->getCT() > 0)
        {
            RunningProcess->setCT(RunningProcess->getCT() - 1);
			timeforrequest++;
            expectedtime--;


            if (RunningProcess->getnIO() > 0 && timeforrequest == RunningProcess->seeTimeForAskForIO())
            {
                IORequest = new Process(*RunningProcess);
				timeforrequest = 0;
				RunningProcess = nullptr;
				TerminatProcess = nullptr;
				return;
            }

            cout << "Step" << endl;
            return;
        }
        else
        {
            TerminatProcess = new Process(*RunningProcess);
            RunningProcess = nullptr;
			IORequest = nullptr;
			timeforrequest = 0;
			return;
        }
    }


    if (ReadyQueue.IsEmpty())
    {
        cout << "SJP Ready Empty" << endl;
		TerminatProcess = nullptr;
		IORequest = nullptr;
		timeforrequest = 0;
        return;
    }


    Process* shortestJob = ReadyQueue.Peek();
    ReadyQueue.Dequeue_In_Variable(shortestJob);

    RunningProcess = shortestJob;
    cout << "Enter new element" << endl;
	TerminatProcess = nullptr;
	IORequest = nullptr;
	return;
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
bool ShortestJobProcessor::isthisProcessrEmpty()
{
	if (this->ReadyQueue.IsEmpty())
		return true;
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
		StolenProcess = new Process(*ReadyQueue.returnkth(ReadyQueue.Count() - 1));
		expectedtime = expectedtime - ReadyQueue.returnkth(ReadyQueue.Count() - 1)->getCT();
		ReadyQueue.DeleteNodePlace(ReadyQueue.Count() - 1);
	}
	return StolenProcess;
}