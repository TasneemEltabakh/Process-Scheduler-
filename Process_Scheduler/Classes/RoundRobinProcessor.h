#pragma once
#include "Processor.h"
class RoundRobinProcessor :
    public Processor
{
public:
    RoundRobinProcessor();
    void SetSLICETIME(int sliceTime);
    ~RoundRobinProcessor();
    void SetRTF(int);
    void ScheduleAlgo() override;
private:
    int sliceTime;
    int RTF;
};

