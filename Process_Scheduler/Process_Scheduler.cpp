
#include <iostream>
#include "DataStructures/LinkedQueue.h"
#include "Scheduler.h"
#include "Classes/FirstComeProcessor.h"

int main()
{

    cout << "enter your input file name: " << endl;
    string name;
    cin >> name;
    Scheduler Schedule(name);
    Schedule.Run();
    /*Process p1(1, 0, 5, 0);
    Process p2(3, 0, 10, 0);
    FirstComeProcessor fs(5,10);
    fs.AddToMyReadyList(p1);
    fs.AddToMyReadyList(p2);
    fs.ScheduleAlgo();*/

}

