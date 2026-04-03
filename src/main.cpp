#include <iostream>
#include <vector>
#include "printoperations.h"
#include "Soldier.h"

// compile: g++ -o main main.cpp soldierHeaders/soldier.cpp printoperations/printoperations.cpp

// run ./main

int main() {

    // Squad 1
    std::vector<Soldier> squad1;
    squad1.push_back(Soldier("14-a", "Johnson", 100, "M4A1"));
    squad1.push_back(Soldier("15-a", "Oscar", 100, "UMP-45"));
    squad1.push_back(Soldier("16-a", "Upton", 100, "AK-47"));
    squad1.push_back(Soldier("17-a", "Kevin", 100, "PSG1"));

    // Squad 2
    std::vector<Soldier> squad2;
    squad2.push_back(Soldier("20-b", "Cliff", 100, "M4A1"));
    squad2.push_back(Soldier("21-b", "Hyde", 100, "UMP-45"));
    squad2.push_back(Soldier("22-b", "Jake", 100, "AK-47"));
    squad2.push_back(Soldier("23-b", "Paul", 100, "PSG1"));

    printTitle();

    char action;

    printCommandActions();

    do {
        std::cin >> action;

        switch (action) {
            case '1': statusCommand(squad1, squad2);
        break;
            case '2': attackCommands(squad1, squad2);
        break;
            case '3': healCommand(squad1, squad2);
        break;
            default: printCommandActions();
        break;
        }

    } while(action != 'q');

    return 0;
}

