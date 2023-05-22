#pragma once
#include "Process.h"
#include "Classes/Processor.h"

class UI 
{
public:
    UI();
    ~UI();
    void OutPutScreen(LinkedQueue<Process*>& Terminal, LinkedQueue<Process*>& BLK, LinkedList<Processor*>& ProcessorsList, int TotaLNumberOfProcesses, int Numberof_SJF, int Numberof_FCFS, int Numberof_RR, int ThisTimer);
    //void OUT_BUT_FILE(LinkedQueue<Process*>& Terminal, LinkedList<Processor*>& ProcessorsList, int TotaLNumberOfProcesses, int Numberof_SJF, int Numberof_FCFS, int Numberof_RR, int WorkStealing);
    void InPut();
    int getCurrentTime();



private:
    //Scheduler* mainPointer;
};

