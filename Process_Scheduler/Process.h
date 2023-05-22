
#pragma once
#include "Supplementary.h"
#include "DataStructures/LinkedQueue.h"


class Process

{
private:
	int PID, TT, AT, CT, WT, RT, TRT, nIO , RemainingCT, childAT;
	LinkedQueue<int> IOpairs;
	bool iskilled;
	bool Isforking;  //R add
	LinkedQueue<Process*> ForkedList;  //R add
	LinkedQueue<Process*> getChildren();
	Process* HasAChild;
	LinkedQueue<Process*> Children;
	Process* ParentQueue;  //R add
	//bool finished;
	int runningtime;
	int duration;
	int TakeItsChild;
	int AlreadyStealBefore;
	

	int CTstepn; //for UI
	int IO_D; //for UI
	int RTAfterSum;
	
	
public:
	Process();
	Process(int x, int y, int z, int l);
	Process(const Process& other);
	//void addDatatoIOPairs(int x, int y);
	//////////////////////////////////////////
	void addDatatoIOPairs(int x, int y);  //T edit
	int seeTimeForAskForIO();  //R add2
	void seeDurationForAskForIO();
	void dequeueIO();
	~Process();
	int getPID() const;
	int getAT()const;
	int getCT() const;
	int getWT() const;
	int getRT() const;
	int getTRT() const;
	int getTT() const;
	void setCT(int newCT);  
	int getNumberChildren();
	void setNumberChildren();  
	void addruntime(int x);
	int getrunt() const;
	void setStolen();
	int getstolen();
	void calcWT(int w);
	void calcTRT();
	void SetFOrk(); //R add
	void PointToMyChild(Process* child);
	Process* MyChild();
	void SetProcessorId(int x);
	int ProcessorId();
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

	void downDuration();
	int get_duration();
	//n
	int getRemainingCT();
	void setRemainingCT(int remainingCT);
	void setParent(Process* parent);
	void addChild(Process* child);
	LinkedQueue<Process*>& getchildren();
	void set_AT_Cild(int newAT);
	
	void setdurationtozero();

	void setTT(int newTT); //for UI
	void stCTstepn(int newCTstepn);  //for UI
	int getCTstepn();  //for UI
	void setIO_D(int newIO_D);  //for UI in schedual
	int getIO_D();  //for UI
	void setRT(int newIO_D);  //for UI in schedual
	int getRTAfterSum();  //for UI
};

