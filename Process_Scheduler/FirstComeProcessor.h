#pragma once
#include "..//Process_Scheduler/Classes/Processor.h"
class FirstComeProcessor :
    public Processor
{
public:
    FirstComeProcessor();
    ~FirstComeProcessor();
    void ScheduleAlgo();
};

