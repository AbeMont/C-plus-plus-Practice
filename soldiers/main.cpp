#include <iostream>
#include <vector>
#include "soldierHeaders/soldier.h"
#include "printoperations/printoperations.h"

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
    std::string soldierId;

    printCommandActions();

    do {
        std::cin >> action;

        switch (action) {
            case '1': {
                std::vector<Soldier>& squadSelectedToView = selectSquad(squad1, squad2, printSquadVector);
                std::cout << "Report Generated. \n";

                printMemoryAddresses(squad1, squad2, squadSelectedToView);

                pressToContinue();
                printCommandActions();
            }
            break;
            case '2': {
                std::cout << '\n';
                std::cout << "Attack Command \n";
                // First need to ask to return of the id of the soldier who will attack from the vector
                // Second is to get the id of the target
                std::cout << "Select a squad first then choose soldier ID to carry out attack... \n";

                std::vector<Soldier>& squadSelectedToAttack = selectSquad(squad1, squad2, printSquadVector);

                for (Soldier& p : squadSelectedToAttack) {
                    p.setHealth(50); // Modifies the actual object in the vector
                }

                // std::cout << "////////////////////// Should Change ////////////////////// \n";
                // printSquadVector(squadSelected);
                // std::cout << "///////////////////// Original Vector //////////////////// \n";
                // printSquadVector(squad1);

                printMemoryAddresses(squad1, squad2, squadSelectedToAttack);

                std::cout << "Choose Soldier by Id.... \n";
                std::cout << '\n';

                pressToContinue();
                printCommandActions();
            }
            break;
            case '3':
                std::cout << "Heal Command \n";
                printCommandActions();
            break;
            default:
                printCommandActions();
            break;
        }

    } while(action != 'q');

    return 0;
}

