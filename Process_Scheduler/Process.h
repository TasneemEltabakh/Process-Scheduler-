
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
	bool Isforking;  //R add
	LinkedQueue<Process*> ForkedList;  //R add
	Process* ParentQueue;  //R add
	//bool finished;
	int runningtime;

public:
	Process();
	Process(int x, int y, int z, int l, bool askforking);

	~Process();
	int getPID() const;
	int getAT()const;
	int getCT() const;
	int getWT() const;
	int getRT() const;
	int getTRT() const;
	int getTT() const;

	void setCT(int newCT);  //R add

	void addruntime(int x);
	int getrunt() const;
	void calcWT();
	void calcTRT();

	void SetFOrk(); //R add
	bool IsKilled();
	void KillThisProcess();

	//bool Isfinished();
	//void FinishProcess();
	bool findProcess(int i);

	void InsertToIOlist(int x, int y);

	bool checkforklist();  //R add
	bool IsForked();  //R add
	Process* getParentQueue(); //R add
	void setParentQueue(Process* parent); //R add
	Process* getAllList();  //R add
	int operator<< (const Process& c) const;  //R add
};

