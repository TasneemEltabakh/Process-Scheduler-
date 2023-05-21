
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
	int PID, TT, AT, CT, WT, RT, TRT, nIO , RemainingCT, childAT;
	ProcessPairs IOpairs;
	bool iskilled;
	bool Isforking;  //R add
	LinkedQueue<Process*> ForkedList;  //R add
	LinkedQueue<Process*> getChildren();
	Process* Parent;
	LinkedQueue<Process*> Children;
	Process* ParentQueue;  //R add
	//bool finished;
	int runningtime;

	
public:
	Process();
	Process(int x, int y, int z, int l);
	Process(const Process& other);
	//void addDatatoIOPairs(int x, int y);
	//////////////////////////////////////////
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
	void calcWT(int w);
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

	int getnIO();  //R add2

	
	//n
	int getRemainingCT();
	void setRemainingCT(int remainingCT);
	void setParent(Process* parent);
	void addChild(Process* child);
	LinkedQueue<Process*>& getchildren();
	void set_AT_Cild(int newAT);
	

};

