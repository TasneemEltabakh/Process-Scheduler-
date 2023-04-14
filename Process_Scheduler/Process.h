#pragma once
#include "Supplementary.h"

class Process

{
private:
	int PID, TT, AT, CT, WT, RT, TRT,IO;
	int* IO_R= new int[IO];
	int* IO_D= new int[IO];


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

	void setCT(int x);
	void calcWT();
	void setRT(int x);
	void calcTRT();
	void setTT(int x);

	//void setIO(int x);

	bool RRmigration(int RTF);
	bool FCFSmigration(int MaxW);

};

