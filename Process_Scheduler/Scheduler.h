#pragma once
#include "Classes/Processor.h"
#include "DataStructures/QueueADT.h"
#include "Process.h"

class Scheduler
{
private:
	Processor** ProcessorsList = new Processor* [3];
	LinkedQueue<Process> NewList;
public:
	Scheduler();
	~Scheduler();
	void load();
	LinkedQueue<int>* TranslateData(string linedata);
	void CreateProcessors(LinkedQueue<int>* dataProcessor);

};

