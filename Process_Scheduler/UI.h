#pragma once
#include "Process.h"
#include "Classes/Processor.h"

class UI 
{
public:
    UI();
    ~UI();
    void OutPutScreen(LinkedQueue<Process*>& Terminal, LinkedQueue<Process*>& BLK, LinkedList<Processor*>& ProcessorsList, int TotaLNumberOfProcesses, int Numberof_SJF, int Numberof_FCFS, int Numberof_RR, int ThisTimer);
    void InPut();
    int getCurrentTime();

private:
    //Scheduler* mainPointer;
};

