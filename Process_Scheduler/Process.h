#pragma once
class Process

{
private:
	Process* IO ;
	int PID, TT, AT, CT, WT, RT, TRT, IO_R, IO_D, KT;

	enum state {
		NEW,
		RDY,
		RUN,
		BLK,
		TRM,
		ORPH
	};
	static int count ;

public:
	Process();
	~Process();
	int getPID() const;
	int getAT()const;
	int getCT() const;
	int getWT() const;
	int getRT() const;
	int getTRT() const;
	int getTT() const;
	int getIO() const;
	int getKT() const;

	void setPID(int x);
	void setAT(int x);
	void setCT(int x);
	void calcWT();
	void setRT(int x);
	void calcTRT();
	void setTT(int x);
	void setKT(int x);
	void setIO(int x);

	bool RRmigration(int RTF);
	bool FCFSmigration(int MaxW);

};

