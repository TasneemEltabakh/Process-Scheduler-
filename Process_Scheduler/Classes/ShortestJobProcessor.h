#pragma once
#include "Processor.h"
#include "..//DataStructures/PriorityQueue.h"

class ShortestJobProcessor :
    public Processor
{
public:
    ShortestJobProcessor();
    ~ShortestJobProcessor();
    void ScheduleAlgo() override;
    void  AddToMyReadyList(Process* NewProcess) override;
private:

    PriorityQueue<Process*> ReadyQueue; //we need here a sorted queue or priority queue
};

