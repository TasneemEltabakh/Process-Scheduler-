#pragma once
enum State
{
	IDLE,
	busy,
	Stop,
};

enum stateP {
	NEW,
	RDY,
	RUN,
	BLK,
	TRM,
	ORPH
};



struct Pair {
	int first;
	int second;
};