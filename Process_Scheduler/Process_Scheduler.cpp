
#include <iostream>
#include "DataStructures/LinkedQueue.h"
#include "Scheduler.h"

int main()
{
    cout << "enter your input file name: " << endl;
    string name;
    cin >> name;
    Scheduler Schedule(name);

}

