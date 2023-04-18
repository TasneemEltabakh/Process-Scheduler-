#pragma once
#include "Processor.h"

class RoundRobinProcessor :
    public Processor
{
public:
    RoundRobinProcessor(int sliceTime, int RTF);
    ~RoundRobinProcessor();
    void SetRTF(int);
    void ScheduleAlgo() override;
private:
    int id;  //R add
    int sliceTime;
    int RTF;
    void Migrate();  //R add
    //LinkedQueue <Process*> * ReadyQueue; // we choosed queue to be easily dequeued and enqueued during operation
    LinkedQueue <Process*> ReadyQueue; // we choosed queue to be easily dequeued and enqueued during operation

};

