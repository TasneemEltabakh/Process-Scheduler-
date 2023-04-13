#pragma once
#include "Processor.h"
class FirstComeProcessor :
    public Processor
{
public:
    FirstComeProcessor();
    ~FirstComeProcessor();
    void ScheduleAlgo() override;
};

