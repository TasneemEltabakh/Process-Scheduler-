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
    Process* MoveMeToTerminal();
    void  AddToMyReadyList(Process& process) override;
    bool IsThereKilled(int c);
    Process* KillSignal();
    void  AddToRun();
    int getcount() override;
    Process* getkth(int k) override;
    bool CheckIfemptyready() override;
    int getExpectedTime() override;

private:
    //LinkedList <Process*> * ReadyQueue = new  LinkedList <Process*>;
    LinkedList <Process*>  ReadyQueue;
    LinkedList <Process*>  RunQueue;
    LinkedList <Process*>  TRMQueue;
    //static  LinkedList <Process*>  TRMQueue;
    int countOfProcesses;
    int maxw;
    int forkprob;
    LinkedQueue<Process*> Killedprocesses;
    //static LinkedQueue<Process*> Killedprocesses;
    Process* KilledOne;
};


