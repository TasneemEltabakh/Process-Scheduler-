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
    void ScheduleAlgo() override;
    void  AddToMyReadyList(Process* NewProcess) override;
    void  AddToRun();
private:
    int sliceTime;
    int RTF;
    LinkedQueue <Process*> * ReadyQueue; // we choosed queue to be easily dequeued and enqueued during operation
};

