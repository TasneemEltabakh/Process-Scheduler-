#pragma once
#include "Processor.h"

class RoundRobinProcessor :
    public Processor
{
public:
    RoundRobinProcessor(int sliceTime, int RTF);
    RoundRobinProcessor();
    ~RoundRobinProcessor();
    void SetRTF(int);
    Process* MoveMeToTerminal();
    void ScheduleAlgo() override;
    void  AddToMyReadyList(Process& process) override;
    void  AddToRun();
    int getcount() override;
    Process* getkth(int k) override;
    bool CheckIfemptyready();
    int getExpectedTime() override;

    int getsliceTime();
    void setsliceTime(int newtime);  //It is constant for each processor
private:
    int sliceTime;
    int InternalsliceTime;  //R add for RP Algo Fun Important that static
    int RTF;
    int countOfProcesses;
    LinkedQueue <Process*>  ReadyQueue; // we choosed queue to be easily dequeued and enqueued during operation
};

