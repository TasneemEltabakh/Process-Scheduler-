#include "RoundRobinProcessor.h"

RoundRobinProcessor::RoundRobinProcessor(int sliceTime, int RTF) {

	this->sliceTime = sliceTime;
	this->RTF = RTF;
}

RoundRobinProcessor::~RoundRobinProcessor(){}
void RoundRobinProcessor::ScheduleAlgo()
{
	/*Process* current, c2;   //Ariam Work

	for (int i = 0; i < (sliceTime * countOfProcesses); i + sliceTime) {
		if(RunningProcess != nullptr)
			ReadyQueue->enqueue(RunningProcess);

		ReadyQueue->Dequeue_In_Variable(current);
		RunningProcess = current;

	}*/

	//if (ReadyQueue.IsEmpty()) {

	//}
	//else if (!ReadyQueue.IsEmpty() && RunningProcess == nullptr) {
	//	ReadyQueue.Dequeue_In_Variable(RunningProcess);
	//}
	//else {
	//	for (int i = 0; i < (sliceTime * countOfProcesses); i + sliceTime) {
	//			ReadyQueue.enqueue(RunningProcess);
	//			ReadyQueue.Dequeue_In_Variable(RunningProcess);

	//	}
	//}
	//
	////Process* current, c2;
	//

	for (int i = 0; i < (sliceTime * countOfProcesses); i + sliceTime) {
		if (ReadyQueue.IsEmpty()) {
			cout << "The Ready List is Empty" << endl;
			return;
		}
		else if (!ReadyQueue.IsEmpty() && RunningProcess == nullptr) {
			ReadyQueue.Dequeue_In_Variable(RunningProcess);
		}
		else {
			//Process* newProcess = new Process;
			//newProcess = RunningProcess;
			ReadyQueue.enqueue(RunningProcess);
			ReadyQueue.Dequeue_In_Variable(RunningProcess);
		}

		//for (int j = 0; j < sliceTime; j++) {
		//	if (RunningProcess->getCT() == 0) {
		//		                              //Here the previuse must go to TERM
		//	}
		//}

		if (RunningProcess->getCT() <= sliceTime) {
			for (int j = 0; j < sliceTime; j++) {
				if (RunningProcess->getCT() == 0) {
					//Here the previuse must go to TERM
				}
				else {
					RunningProcess->setCT(RunningProcess->getCT() - 1);
				}
			}
		}
		else {
			RunningProcess->setCT(RunningProcess->getCT() - sliceTime);
		}

	}
	//cout << "HI this is Algo for round " << endl;
}

void RoundRobinProcessor::SetRTF(int rt) {
	RTF = rt;

}
//void RoundRobinProcessor::Migrate() {
	//for (int i = 0; i < ReadyQueue.Count(); i++) {
	//	Node* temp= ReadyQueue.gethead();
	//	//Node<T>* tmp;
	//	tmp = head;
	//	while (tmp != NULL)
	//	{
	//		cout << tmp->data << endl;
	//		tmp = tmp->next;
	//	}
	//}
//}

void RoundRobinProcessor::AddToMyReadyList(Process* NewProcess)
{
	ReadyQueue->enqueue(NewProcess);
	cout << "HI this is Algo for round " << endl;
}
void RoundRobinProcessor::AddToRun()
{
	ProcessorState = busy;
	if (ReadyQueue->IsEmpty()) {
		return;
	}
	ReadyQueue->Dequeue_In_Variable(RunningProcess);
	cout << RunningProcess->getPID() << endl;
}