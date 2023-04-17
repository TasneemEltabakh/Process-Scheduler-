
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

public:

	Process(int x, int y, int z, int l);

	~Process();
	int getPID() const;
	int getAT()const;
	int getCT() const;
	int getWT() const;
	int getRT() const;
	int getTRT() const;
	int getTT() const;


	void calcWT();
	void calcTRT();

	bool IsKilled();
	void KillThisProcess();


	void InsertToIOlist(int x, int y);

};

