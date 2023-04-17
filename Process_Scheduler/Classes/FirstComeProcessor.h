#pragma once
#include "Processor.h" 
#include "..//Scheduler.h"

class FirstComeProcessor :
    public Processor
{
public:
    FirstComeProcessor(int MX, int FORK);
    ~FirstComeProcessor();
    void SetMAXW(int);
    void ScheduleAlgo() override;
    Process* ForkingCheck();
    bool IsThereKilled();
    void KillSignal(Scheduler* schud);

private:
    LinkedList<Process>* ReadyQueue; // we choosed linked list to be easily killed during operation
    int maxw;
    int forkprob;
};

