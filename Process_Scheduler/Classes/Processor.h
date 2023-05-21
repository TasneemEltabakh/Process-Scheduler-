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
	virtual Process* MoveMeToTerminal() = 0;
	bool IsIDlE() const;
	Process* RunningNow();
	void RunningIsFree();
	virtual int getcount() = 0;
	virtual Process* getkth(int k) = 0;
	int getId();
	bool RunningaProcess();
	Process* TerminatedProcess();
	bool CheckIfRun(); 
	virtual bool CheckIfemptyready() = 0;
	int getnowctforrunning();
	void CurrentTime(int time);
	
protected:
	Process* RunningProcess;   //****************

	State ProcessorState;
	Process* TerminatProcess;
	double load;
	double utilization;
	int TimerOfReadyList;
	int runingTime;
	static int Count;
	int downtimer;
	int Id;
	int currentTime;

	

};

