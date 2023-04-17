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

};

