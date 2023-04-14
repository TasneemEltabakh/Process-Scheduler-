#pragma once
#include "Processor.h"
class FirstComeProcessor :
    public Processor
{
public:
    FirstComeProcessor();
    ~FirstComeProcessor();
    void SetMAXW(int);
    void ScheduleAlgo() override;
private:
    int Maxw;
};

