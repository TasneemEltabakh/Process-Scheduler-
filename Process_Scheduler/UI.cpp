#include "UI.h"
#include "DataStructures/LinkedQueue.h"
#include "DataStructures/PriorityQueue.h"
#include "DataStructures/LinkedList.h"
#include "Process.h"
#include "Classes/Processor.h"
#include<fstream>
#include <iomanip>

UI::UI() {

}
UI::~UI()
{
}
void UI::InPut() {

}

void UI::OutPutScreen(LinkedQueue<Process*>& Terminal, LinkedQueue<Process*>& BLK, LinkedList<Processor*>& ProcessorsList,int TotaLNumberOfProcesses,int Numberof_SJF,int Numberof_FCFS,int Numberof_RR, int ThisTimer) {
	cout <<endl<< "current time  : "<< ThisTimer << endl;
	cout << "-------------RDY Processes------------" << endl;
	
	for (int i = 0; i < (Numberof_FCFS+Numberof_RR+Numberof_SJF); i++) {
		if (ProcessorsList.returnkth(i)->getId() >= 1 && ProcessorsList.returnkth(i)->getId() <= Numberof_FCFS) {
			cout << endl<< "processor " << ProcessorsList.returnkth(i)->getId() << " [FCFS]: " << ProcessorsList.returnkth(i)->getcount() << " RDY: ";
			for (int j = 0; j < ProcessorsList.returnkth(i)->getcount(); j++) {
				
					cout << (ProcessorsList.returnkth(i))->getkth(j)->getPID() << ", ";
			}
			
		}else if (ProcessorsList.returnkth(i)->getId() >= Numberof_FCFS+1 && ProcessorsList.returnkth(i)->getId() <= Numberof_FCFS + Numberof_SJF) {
			cout << endl << "processor " << ProcessorsList.returnkth(i)->getId() << " [SJF]: " << ProcessorsList.returnkth(i)->getcount() << " RDY: ";
			for (int j = 0; j < ProcessorsList.returnkth(i)->getcount(); j++) {
			
					cout << (ProcessorsList.returnkth(i))->getkth(j)->getPID() << ", ";
			}
			
		}else if(ProcessorsList.returnkth(i)->getId() >= Numberof_FCFS + Numberof_SJF +1 && ProcessorsList.returnkth(i)->getId() <= Numberof_FCFS + Numberof_SJF + Numberof_RR) {
			cout << endl << "processor " << ProcessorsList.returnkth(i)->getId() << " [RR]: " << ProcessorsList.returnkth(i)->getcount() << " RDY: ";
			for (int j = 0; j < ProcessorsList.returnkth(i)->getcount(); j++) {
				
				cout << (ProcessorsList.returnkth(i))->getkth(j)->getPID() << ", ";
			}
		
		}
		
	}

	cout <<endl << "-------------BLK Processes------------" << endl;
	cout << BLK.Count() << " " << "BLK: ";

	for (int k = 0; k < BLK.Count(); k++) {
		
		cout << BLK.returnkth(k)->getPID() << ", ";
	}
	cout << endl<< "-------------RUN Processes------------" << endl;
	int c=0;
	for (int k = 0; k < ProcessorsList.Count(); k++) {
		if (ProcessorsList.returnkth(k)->CheckIfRun()) {
			c = c + 1;
		}
	}
	cout << c << " RUN: ";
	
	for (int k = 0; k < ProcessorsList.Count(); k++) {
		if (ProcessorsList.returnkth(k)->CheckIfRun()) {
			cout << ProcessorsList.returnkth(k)->RunningNow()->getPID() << "(P" << ProcessorsList.returnkth(k)->getId() << ")" << ", ";
		}
	}

	cout << endl<< "-------------TRM Processes------------" << endl;
	int c1 = 0;
	for (int k = ProcessorsList.Count(); k < Terminal.Count(); k++) {
			c1 = c1 + 1;
	}
	cout << c1 << " " << "TRM: ";
	for (int k = ProcessorsList.Count(); k < Terminal.Count(); k++) {
		if (Terminal.returnkth(k) != nullptr) {
			cout << Terminal.returnkth(k)->getPID() << ", ";
		}
	}
}

void UI::OUT_BUT_FILE(LinkedQueue<Process*>& Terminal, LinkedList<Processor*>& ProcessorsList, int TotaLNumberOfProcesses, int Numberof_SJF, int Numberof_FCFS, int Numberof_RR)
{
	int SUMWT = 0;
	int count = 0;
	for (int k = ProcessorsList.Count(); k < Terminal.Count(); k++) {
		SUMWT = SUMWT + Terminal.returnkth(k)->getWT();
	}
	int AVGWT = SUMWT / count;


	int SUMRT = 0;
	for (int k = ProcessorsList.Count(); k < Terminal.Count(); k++) {
		SUMRT = SUMRT + Terminal.returnkth(k)->getRTAfterSum();
	}
	int AVRT = SUMRT / count;


	int SUMTRT = 0;
	for (int k = ProcessorsList.Count(); k < Terminal.Count(); k++) {
		SUMTRT = SUMTRT + Terminal.returnkth(k)->getTRT();
	}
	int AVGTRT = SUMTRT / count;


	ofstream outfile;  //for UI
	outfile.open("output.txt");
	outfile <<left << setw(5) << "TT"<<left << setw(5) << "PID" << left << setw(5) << "AT" << left << setw(5) << "CT" << left << setw(5) << "IO_D" << left << setw(5) << "WT" << left << setw(5) << "RT" << left << setw(5) << "TRT" "\n";
	for (int k = ProcessorsList.Count(); k < Terminal.Count(); k++) {
		outfile << left << setw(5)<< Terminal.returnkth(k)->getTT() << left << setw(5) << Terminal.returnkth(k)->getPID()<< left << setw(5) << Terminal.returnkth(k)->getAT()<< left << setw(5) << Terminal.returnkth(k)->getCT()<< left << setw(5) << Terminal.returnkth(k)->getIO_D() << left << setw(5) << Terminal.returnkth(k)->getWT()<< left << setw(5) << Terminal.returnkth(k)->getRTAfterSum()<< left << setw(5) << Terminal.returnkth(k)->getTRT() << "\n";
	}
	outfile << "\n\n";
	
	/*Node<Process*>* pointer = Terminal.gethead();
	for (int k = 0; k < Terminal.Count(); k++) {
		if (pointer->getItem()) {
			break;
		}
		outfile << pointer->getItem()->getTT() << " " << pointer->getItem()->getPID() << " " << pointer->getItem()->getAT() << " " << pointer->getItem()->getCT() << " " << 10 << " " << pointer->getItem()->getWT() << " " << pointer->getItem()->getRT() << " " << pointer->getItem()->getTRT() << "\n";
		pointer = pointer->getNext();
	}*/
	
	
	outfile << "Processes: " << TotaLNumberOfProcesses << "\n" << "Avg WT= " << AVGWT << ",   Avg RT = " << AVRT << ",   Avg TRT = " << AVGTRT << "\n";
	outfile << "Migration %: " <<  "RTF= " << 10 << "%, MaxW = " << 10 << "%"<< "\n";
	outfile << "Work Steal%: " << 10 << "%" << "\n";
	outfile << "Forked Process: " << 10 << "%" << "\n";
	outfile << "Killed Process: " << 10 << "%" << "\n\n";


	outfile << "Processors: "<< ProcessorsList.Count()<<" ["<< Numberof_FCFS<<" FCFS, "<< Numberof_SJF<<" SJF, " << Numberof_RR<<" RR]" << "\n";
	outfile << "Processors Load " << "\n";
	for (int i = 0; i < ProcessorsList.Count();i++) {
		outfile << "p" << i + 1 << "=" << 10 << "%,   ";
	}
	outfile << "\n";
	outfile << "Processors Utiliz " << "\n";
	for (int i = 0; i < ProcessorsList.Count(); i++) {
		outfile << "p" << i + 1 << "=" << 10 << "%,   ";
	}
	outfile << "\n";
	outfile << "Avg Utilization =  "<<10<<"% " << "\n";


	outfile.close();
}