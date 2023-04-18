#pragma once
#include "Processor.h"
#include "..//Scheduler.h"
class ShortestJobProcessor :
    public Processor
{
public:
    ShortestJobProcessor();
    ~ShortestJobProcessor();
    void ScheduleAlgo() override;
private:

    LinkedQueue<Process*> ReadyQueue; //we need here a sorted queue or priority queue
};

