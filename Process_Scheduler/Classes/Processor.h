#pragma once
#include"..//DataStructures/QueueADT.h"
#include "..//DataStructures/LinkedQueue.h"
#include "..//DataStructures/LinkedList.h"
#include "..//Supplementary.h"
#include "..//Process.h"

class Processor
{
public:
	Processor();
	virtual void  ScheduleAlgo() = 0;
	~Processor();
	virtual void  AddToMyReadyList(Process* NewProcess) = 0;
	virtual void  AddToRun() = 0;
    Process* MoveMeToTerminal();
	bool IsIDlE() const;
	Process* RunningNow();
	void RunningIsFree();
	virtual int getcount() = 0;
	int getId();

	bool CheckIfRun();  //R add
protected:
	Process* RunningProcess;
	State ProcessorState;
	double load;
	double utilization;
	int TimerOfReadyList;
	int runingTime;
	static int Count;
	int Id;

	

};

