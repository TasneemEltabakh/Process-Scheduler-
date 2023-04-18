#pragma once
#include "Processor.h" 
#include "..//Scheduler.h"

class FirstComeProcessor :
    public Processor
{
public:
    FirstComeProcessor(int MX, int FORK);
    FirstComeProcessor();
    ~FirstComeProcessor();
    void SetMAXW(int max);
    void ScheduleAlgo() override;

    void ForkingCheck();
    void  AddToMyReadyList(Process* NewProcess) override;
    bool IsThereKilled(int c);
    Process* KillSignal();


private:
    //LinkedList <Process*> * ReadyQueue = new  LinkedList <Process*>;
    LinkedList <Process*> ReadyQueue;

    int maxw;
    int forkprob;
    Process* KilledOne;
};

