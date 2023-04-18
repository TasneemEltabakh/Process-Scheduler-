#pragma once
#include "Processor.h" 
#include "..//Scheduler.h"

class FirstComeProcessor :
    public Processor
{
public:
    FirstComeProcessor(int MX, int FORK);
    ~FirstComeProcessor();
    void SetMAXW(int max);
    void ScheduleAlgo() override;

    void ForkingCheck();
    bool IsThereKilled();
    void KillSignal(Scheduler* schud);

private:
    LinkedQueue <Process*>  ReadyQueue; // we choosed linked list to be easily killed during operation
    int maxw;
    int forkprob;
};

