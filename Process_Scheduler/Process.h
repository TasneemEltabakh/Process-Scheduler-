
#pragma once
#include "Supplementary.h"
#include "DataStructures/LinkedQueue.h"

struct ProcessPairs {
	int x;
	int y;
	LinkedQueue<pair<int, int>> pairs;
};



class Process

{
private:
	int PID, TT, AT, CT, WT, RT, TRT, nIO;
	ProcessPairs IOpairs;
	bool iskilled;
	bool Isforking;  //R add
	LinkedQueue<Process*> ForkedList;  //R add
	Process* ParentQueue;  //R add
	//bool finished;
	int runningtime;

	//Phase Two
	bool askedforOI; //R add2
	bool IsFinshed; //R add2
	
public:
	Process();
	Process(int x, int y, int z, int l);
	Process(const Process& other);

	void addDatatoIOPairs(int x, int y);  //T edit
	int seeTimeForAskForIO();  //R add2


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
	bool findProcess(int i);
	void InsertToIOlist(int x, int y);
	bool checkforklist();  //R add
	bool IsForked();  //R add
	Process* getParentQueue(); //R add
	void setParentQueue(Process* parent); //R add
	Process* getAllList();  //R add
	int operator<< (const Process& c) const;  //R add


	//Phase Two
	void setaskedforOI(bool state); //R add2
	void setIsFinshed(bool state); //R add2
	bool getaskedforOI(); //R add2
	bool getIsFinshed(); //R add2

};

