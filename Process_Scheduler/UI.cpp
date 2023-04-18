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

	for (int i = 0; i < (Numberof_FCFS+Numberof_RR+Numberof_SJF); i++) {
		if (ProcessorsList.returnkth(i)->getId() >= 1 && ProcessorsList.returnkth(i)->getId() <= Numberof_FCFS) {
			cout << endl<< "processor " << ProcessorsList.returnkth(i)->getId() << " [FCFS]: " << ProcessorsList.returnkth(i)->getcount() << " RDY: ";
			for (int j = 0; j < Numberof_FCFS; j++) {
				cout<<(ProcessorsList.returnkth(j))->getId() << ", ";
			}
			
		}else if (ProcessorsList.returnkth(i)->getId() >= Numberof_FCFS+1 && ProcessorsList.returnkth(i)->getId() <= Numberof_FCFS + Numberof_SJF) {
			cout << endl << "processor " << ProcessorsList.returnkth(i)->getId() << " [SJF]: " << ProcessorsList.returnkth(i)->getcount() << " RDY: ";
			for (int j = Numberof_FCFS; j < Numberof_FCFS + Numberof_SJF; j++) {
				cout << (ProcessorsList.returnkth(j))->getId() << ", ";
			}
			
		}else if(ProcessorsList.returnkth(i)->getId() >= Numberof_FCFS + Numberof_SJF +1 && ProcessorsList.returnkth(i)->getId() <= Numberof_FCFS + Numberof_SJF + Numberof_RR) {
			cout << endl << "processor " << ProcessorsList.returnkth(i)->getId() << " [RR]: " << ProcessorsList.returnkth(i)->getcount() << " RDY: ";
			for (int j = Numberof_FCFS + Numberof_SJF; j < Numberof_FCFS + Numberof_SJF+Numberof_RR; j++) {
				cout<< (ProcessorsList.returnkth(j))->getId() << ", ";
			}
		
		}
		
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