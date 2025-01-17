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
	virtual void  AddToMyReadyList(Process& process) = 0;
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
	virtual int getExpectedTime() = 0;
	virtual Process* RemoveProcess() = 0;
	bool StoppedCheck();
	void OutOfService(int n);
	void BacktoService();
	int CountDownBreak();
	Process* getIO();
	Process* getTerminal();
	void setIORequest(Process* request);
	virtual bool isthisProcessrEmpty()=0;
	
protected:
	Process* RunningProcess; 
	Process Running;
	State ProcessorState;
	Process* TerminatProcess;  ///****************
	Process* IORequest;  ///****************
	double load;
	double utilization;
	int TimerOfReadyList;
	int runingTime;
	int breaktime;
	static int Count;
	int downtimer;
	int Id;
	int currentTime;  //************
	int expectedtime;
	int getRunningCt;
	State processor;
	int timeforrequest;
};

