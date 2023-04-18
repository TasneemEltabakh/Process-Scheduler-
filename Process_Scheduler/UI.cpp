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

void UI::OutPutScreen(LinkedQueue<Process*>& Terminal, LinkedQueue<Process*>& BLK, LinkedList<Processor*>& ProcessorsList,int TotaLNumberOfProcesses,int Numberof_SJF,int Numberof_FCFS,int Numberof_RR) {
	//cout << CurrentTime<<endl;
	cout << "-------------RDY Processes------------" << endl;
	int id=1;
	for (int i = 0; i < TotaLNumberOfProcesses; i++) {
		if (id == 1) {
			cout << "processor " << id << " [FCFS]: " << Numberof_FCFS << " RDY: ";
			for (int j = (Numberof_RR + Numberof_SJF); j < ProcessorsList.Count(); j++) {
				cout << ProcessorsList.returnkth(j) << ", ";
			}
		}else if (id == 2) {
			cout << endl << "processor " << id << " [SJF]: " << Numberof_SJF << " RDY: ";
			for (int j = (Numberof_RR); j < Numberof_RR + Numberof_SJF; j++) {
				cout << ProcessorsList.returnkth(j) << ", ";
			}
		}else if(id == 3) {
			cout << endl << "processor " << id << " [RR]: " << Numberof_RR << " RDY: ";
			for (int j = 0; j < Numberof_RR; j++) {
				cout<< ProcessorsList.returnkth(j) << ", ";
			}
		}
		id = id + 1;
			
	}

	cout <<endl << "-------------BLK Processes------------" << endl;
	cout << BLK.Count() << " " << "BLK: ";
	BLK.Display();
	cout << endl<< "-------------RUN Processes------------" << endl;
	cout << ProcessorsList.Count() << " RUN: ";


	cout << endl<< "-------------TRM Processes------------" << endl;
	cout << Terminal.Count() << " " << "TRM: ";
	Terminal.Display();
}