
#include <iostream>
#include "DataStructures/LinkedQueue.h"
#include "Scheduler.h"
#include "UI.h"

int main()
{
    cout << "enter your input file name: " << endl;
    string name;
    cin >> name;
    Scheduler Schedule(name);

    //UI output;    //R add  only to test the view of out put
    //output.OutPutScreen(Schedule.Terminal, Schedule.BLK, Schedule.ProcessorsList);  //R add
}

