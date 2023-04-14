#include "Scheduler.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Process.h"
#include "Classes/FirstComeProcessor.h"
#include "Classes/RoundRobinProcessor.h"
#include "Classes/ShortestJobProcessor.h"
#include "Classes/Processor.h"


Scheduler::Scheduler()
{
	load();
}
Scheduler::~Scheduler()
{

}
void Scheduler::load()
{
		ifstream InputFile;
		int counter = 0;
		InputFile.open("Input_File.txt");

		if (InputFile.is_open()) {
			while (!InputFile.eof())
			{
				counter++;
				string* line = new string;
				getline(InputFile, *line);
			
				if (counter == 1)
				{
					LinkedQueue<int>* PROCDATA= TranslateData(*line);
					getline(InputFile, *line);
					CreateProcessors(PROCDATA, stoi(* line));
				}
				delete line;
			}
			
		}
		else {
			cout << "Couldn't open file\n";
		}
		InputFile.close();
	
}
LinkedQueue<int>* Scheduler ::TranslateData(string linedata) //this Function Splits the string of one line into information for the system
{
	LinkedQueue<int>* dataList = new LinkedQueue<int>;
	int i = 0;
	string data;
	char x = linedata.at(i);
	while (i< linedata.size()-1)
	{
		if (x != ' ') {
			data = data + x;
			i++;
			x = linedata.at(i);
		}
		else
		{
			dataList->enqueue(stoi(data));
			data.clear();
			i++;
			x = linedata.at(i);
		}
	}
	return dataList;
}
void inline  Scheduler:: CreateProcessors(LinkedQueue<int>* dataProcessor, int SliceRR) //this function Creates processors of each type by the required count and adds them to the processors list 
{
	int Numberof_FCFS, Numberof_RR, Numberof_SJF;
	dataProcessor->dequeue(Numberof_FCFS);
	dataProcessor->dequeue(Numberof_SJF);
	dataProcessor->dequeue(Numberof_RR);
    FirstComeProcessor* FCFS_List = new FirstComeProcessor[Numberof_FCFS];
	RoundRobinProcessor* RR_List = new RoundRobinProcessor[Numberof_RR];
	ShortestJobProcessor* SJF_List = new ShortestJobProcessor[Numberof_SJF];
	for (int i = 0; i < Numberof_RR; i++)
	{
		RR_List[i] = RoundRobinProcessor(SliceRR);
	}
	ProcessorsList[0] = FCFS_List;
	ProcessorsList[1] = RR_List;
	ProcessorsList[2] = SJF_List;

}
