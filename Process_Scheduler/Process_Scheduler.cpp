
#include <iostream>
#include "DataStructures/LinkedQueue.h"
#include "Scheduler.h"
#include "Classes/FirstComeProcessor.h"
#include<fstream>


int main()
{

    cout << "enter your input file name: " << endl;
    string name;
    cin >> name;
    Scheduler Schedule(name);
    Schedule.Run();
  
}

