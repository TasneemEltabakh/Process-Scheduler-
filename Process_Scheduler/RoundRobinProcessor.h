#pragma once
#include "Classes/Processor.h"
class RoundRobinProcessor :
    public Processor
{
public:
    RoundRobinProcessor();
    ~RoundRobinProcessor();
    void ScheduleAlgo() override;

};

