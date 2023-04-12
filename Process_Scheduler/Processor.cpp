#include "Processor.h"
#include "Supplementary.h"

Processor::Processor()
{
	ProcessorState = IDLE;
	pLoad = 0;
	pUtil = 0;
	timer = 0;
}
Processor::~Processor(){}

