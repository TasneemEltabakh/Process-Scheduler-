#pragma once
enum State
{
	IDLE,
	busy,
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