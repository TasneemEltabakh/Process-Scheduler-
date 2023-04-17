#include "Scheduler.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Process.h"
#include "Classes/FirstComeProcessor.h"
#include "Classes/RoundRobinProcessor.h"
#include "Classes/ShortestJobProcessor.h"
#include "Classes/Processor.h"


Scheduler::Scheduler(string inputfilename)
{
	load(inputfilename);
}
Scheduler::~Scheduler()
{

}
void Scheduler::load(string inputfile)
{
	ifstream InputFile;
	int counter=0;
	InputFile.open(inputfile+ ".txt");

	if (InputFile.is_open()) {
		while (!InputFile.eof())
		{
			string* line = new string;
			LinkedQueue<string>* Data = new LinkedQueue<string>;

	
			for (int i = 0; i < 3; i++)
			{
				counter++;
				getline(InputFile, *line);
				TranslateData(*line, Data);
			}
			if (counter == 3) {
				CreateProcessors(Data); 
				counter++;
			}
			if (counter == 4) {
				getline(InputFile, *line); 
				TotaLNumberOfProcesses = stoi(*line);
			}
			for (int i = 0; i < TotaLNumberOfProcesses; i++)
			{
				LinkedQueue<string>* newd = new LinkedQueue<string>;
				getline(InputFile, *line);
				TranslateData(*line, newd);
				InsertProcessToNew(newd);
				counter++;
			}
			if (counter == 4 + TotaLNumberOfProcesses) break;

			//delete line;
		}
			
	}
	else {
		cout << "Couldn't open file\n";
	}
	InputFile.close();
	
}
void Scheduler ::TranslateData(string linedata, LinkedQueue<string>*  dataP) //this Function Splits the string of one line into information for the system
{
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
			dataP->enqueue(data);
			
			data.clear();
			i++;
			x = linedata.at(i);
		}
	}
	
}
void Scheduler::RemoveParenthesis(string linedata, LinkedQueue<int>* dataProcessor)
{
	int n1 = linedata.find("(");
	int n2 = linedata.find(")");
	int n3 = linedata.find(",");
	string FirstNumber, SecondNumber;
	for (int i = n1 + 1; i < n3; i++)
	{
		FirstNumber = FirstNumber + linedata.at(i);
		
	}
	for (int i = n3 + 1; i < n2; i++)
	{
		SecondNumber = SecondNumber + linedata.at(i);

	}
	dataProcessor->enqueue(stoi(FirstNumber));
	dataProcessor->enqueue(stoi(SecondNumber));

}
void  Scheduler:: CreateProcessors(LinkedQueue<string>* dataProcessor) //this function Creates processors of each type by the required count and adds them to the processors list 
{
	string slicetime, rtf, fork, stl, maxw, Numberof_FC, Numberof_SJ, Numberof_R;
	dataProcessor->dequeue(Numberof_FC);
	dataProcessor->dequeue(Numberof_SJ);
	dataProcessor->dequeue(Numberof_R);
	dataProcessor->dequeue(slicetime);
	dataProcessor->dequeue(rtf);
	dataProcessor->dequeue(maxw);
	dataProcessor->dequeue(stl);
	dataProcessor->dequeue(fork);
	Numberof_SJF = stoi(Numberof_SJ);
	Numberof_RR = stoi(Numberof_R);
	Numberof_FCFS = stoi(Numberof_FC);


	for (int i = 0; i < Numberof_RR; i++)
	{
		ProcessorsList.InsertBeg(new RoundRobinProcessor(stoi(slicetime), stoi( rtf)));
	}
	for (int i = 0; i < Numberof_SJF; i++)
	{
		ProcessorsList.InsertBeg(new ShortestJobProcessor());
	}
	for (int i = 0; i < Numberof_FCFS; i++)
	{
		ProcessorsList.InsertBeg(new FirstComeProcessor(stoi(maxw),stoi(fork)));
	}
}
void  Scheduler::InsertProcessToNew(LinkedQueue<string>* dataProcess)
{
	string At, id, ct, nio, iop;
	int IoR, IoD;

	dataProcess->dequeue(At);
	dataProcess->dequeue(id);
	dataProcess->dequeue(ct);
	dataProcess->dequeue(nio);

	Process* newprocess = new Process(stoi(At), stoi(id), stoi(ct), stoi(nio));

	if (stoi(nio) != 0)
	{
		LinkedQueue<int>* Data = new LinkedQueue<int>;
		dataProcess->dequeue(iop);
		RemoveParenthesis(iop, Data);
		Data->dequeue(IoR);
		Data->dequeue(IoD);
		delete Data;
		newprocess->InsertToIOlist(IoR, IoD);
		cout << IoR << endl << IoD;
	}

	
	
}