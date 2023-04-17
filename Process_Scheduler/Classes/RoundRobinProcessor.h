#pragma once
#include "Processor.h"

class RoundRobinProcessor :
    public Processor
{
public:
    RoundRobinProcessor(int sliceTime, int RTF);
    ~RoundRobinProcessor();
    void ScheduleAlgo() override;
private:
    int sliceTime;
    int RTF;
    LinkedQueue<Process>* ReadyQueue; // we choosed queue to be easily dequeued and enqueued during operation
};

