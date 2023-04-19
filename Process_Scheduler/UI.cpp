#include "UI.h"
#include "DataStructures/LinkedQueue.h"
#include "DataStructures/PriorityQueue.h"
#include "DataStructures/LinkedList.h"
#include "Process.h"
#include "Classes/Processor.h"

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
	cout << Terminal.Count() << " " << "TRM: ";
	for (int k = 0; k < Terminal.Count(); k++) {
		cout << Terminal.returnkth(k)->getPID() << ", ";
	}
}