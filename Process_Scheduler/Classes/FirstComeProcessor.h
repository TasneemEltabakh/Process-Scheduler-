#pragma once
#include "Processor.h"
class FirstComeProcessor :
    public Processor
{
public:
    FirstComeProcessor(int MX, int FORK);
    ~FirstComeProcessor();
    void ScheduleAlgo() override;
    Process* ForkingCheck();

private:
    int maxw;
    int forkprob;
};

