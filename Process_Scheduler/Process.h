
#pragma once
#include "Supplementary.h"
#include "DataStructures/LinkedQueue.h"

class Process

{
private:
	int PID, TT, AT, CT, WT, RT, TRT, nIO;
	string IOPairS;
	LinkedQueue<int> IOpairs;
	bool iskilled;
	//bool finished;
	int runningtime;

public:
	Process();
	Process(int x, int y, int z, int l);

	~Process();
	int getPID() const;
	int getAT()const;
	int getCT() const;
	int getWT() const;
	int getRT() const;
	int getTRT() const;
	int getTT() const;
	void addruntime(int x);
	int getrunt() const;
	void calcWT();
	void calcTRT();

	bool IsKilled();
	void KillThisProcess();

	//bool Isfinished();
	//void FinishProcess();

	void InsertToIOlist(int x, int y);

};

