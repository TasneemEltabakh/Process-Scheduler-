#pragma once
#include "Processor.h"
class RoundRobinProcessor :
    public Processor
{
public:
    RoundRobinProcessor();
    ~RoundRobinProcessor();
    void ScheduleAlgo() override;

};

