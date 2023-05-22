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
    void IsThereKilled(int c);
    Process* KillSignal();
    void  AddToRun();
    int getcount() override;
    Process* getkth(int k) override;
    bool CheckIfemptyready() override;
    int getExpectedTime() override;
    Process* RemoveProcess() override;
    bool ChcekMigration(Process* running);
    bool isthisProcessrEmpty();
    bool ISforked(int x);
    int returnMyRunningCT();
    void SetToRunningChild(Process* child);
    void KillProcessAndChildren(Process* process);
 
private:
    //LinkedList <Process*> * ReadyQueue = new  LinkedList <Process*>;
    LinkedList <Process*>  ReadyQueue;
    LinkedList <Process*>  RunQueue;
    LinkedList <Process*>  TRMQueue;
    //static  LinkedList <Process*>  TRMQueue;
    int countOfProcesses;
    int maxw;
    int wt;
    int forkprob;
   
    LinkedQueue<Process*> Killedprocesses;
    //static LinkedQueue<Process*> Killedprocesses;
    Process* KilledOne;
  
  
   
};


