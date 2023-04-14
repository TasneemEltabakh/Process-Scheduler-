#pragma once
#include "Processor.h"
class RoundRobinProcessor :
    public Processor
{
public:
    RoundRobinProcessor();
    RoundRobinProcessor(int sliceTime);
    ~RoundRobinProcessor();
    void ScheduleAlgo() override;
private:
    int sliceTime;

};

