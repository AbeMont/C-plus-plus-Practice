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
            case '1': {
                std::vector<Soldier>& squadSelectedToView = selectSquad(squad1, squad2, printSquadVector);
                std::cout << "Report Generated. \n";

                pressToContinue();
                printCommandActions();
            }
            break;
            case '2': {
                std::cout << '\n';
                std::cout << "Attack Command \n";
                std::cout << "Select a squad first then choose soldier ID to carry out attack... \n";

                // 1. Select Squad to carry out attack
                std::vector<Soldier>& squadSelectedToAttack = selectSquad(squad1, squad2, printSquadVector);
                
                // 2. Get memory address of attack squad
                std::vector<Soldier>* squadSelectedToAttackPtr = &squadSelectedToAttack;

                // 3. We must check if the memory address of the attack squad matches squad 1 or squad 2, then decide which squad is the attacker and which is the defender
                //    First we create a ref declaration
                std::vector<Soldier>& squadSelectedAstarget = 
                // The pointer squadSelectedToAttackPtr holds the original Memory Address of either squad1 or squad2
                // using (&) we get the Memory Address of squad1 as --> &squad1
                !(squadSelectedToAttackPtr == &squad1) ? squad1 : squad2; 
                
                // 4. From the selected squad, choose a soldier by ID to attack
                Soldier* attacker = selectedSoldierByIdToAttack(squadSelectedToAttack, "Attacker");

                if(attacker) {
                    std::cout << "Successfully selected the attacker \n";
                    std::cout << "\n";
                }

                std::cout << "Now to view the list of the targets \n";
                pressToContinue();
                printSquadVector(squadSelectedAstarget);

                // 5. Select the soldier target
                Soldier* target = selectedSoldierByIdToAttack(squadSelectedAstarget, "Defender");

                if(target) {
                    std::cout << "Successfully Selected the target \n";
                    std::cout << "\n";
                }

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

