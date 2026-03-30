#include <limits>
#include "printoperations.h"
#include <algorithm>

void printTitle() {
    std::cout << '\n';
    std::cout << '\n';
    std::cout << "/////////////////////////////////" << '\n';
    std::cout << "      Deus Ex Machina Program    " << '\n';
    std::cout << "/////////////////////////////////" << '\n';
    std::cout << '\n';
};

void printSquadVector(std::vector<Soldier> &squad) {

    unsigned int vectorSize = squad.size();

    for (unsigned int i = 0; i < vectorSize; i++) {
        std::cout << '\n';
        std::cout << "////////////////////////////////////" << '\n';
        std::cout << "id: " << squad[i].getId() << '\n';
        std::cout << "Name: " << squad[i].getName() << '\n';
        std::cout << "Status: " << squad[i].getStatus() << '\n';
        std::cout << "Health: " << squad[i].getHealth() << '\n';
        std::cout << "Weapon: " << squad[i].getWeapon() << '\n';
        std::cout << "////////////////////////////////////" << '\n';
        std::cout << '\n';
    }
    
};

void printCommandActions() {
    std::cout << "////////////////////////////////////" << '\n';
    std::cout << "Command Center \n";
    std::cout << "////////////////////////////////////" << '\n';
    std::cout << '\n';
    std::cout << "1.) View Squad Status \n";
    std::cout << "2.) Attack Command \n";
    std::cout << "3.) Heal Command \n";
    std::cout << '\n';
    std::cout << "Enter 'q' to quit \n";
    std::cout << '\n';
};

void pressToContinue() {
    std::cout << "Press 'Enter' to continue... \n";
    // Clear the input buffer first in case there is a leftover newline character
    // from a previous input operation (e.g., cin >> variable).
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    // Wait for a single character input (which will be the newline from 'Enter')
    std::cin.get();
}

void printMemoryAddresses(
    std::vector<Soldier>  &squad1, 
    std::vector<Soldier> &squad2, 
    std::vector<Soldier>  &squadSelected) {
    std::cout << "After Memory address for 'squad1' " << &squad1 << '\n'; // 0x7ffd6e428380
    std::cout << "After Memory address for 'squad2' " << &squad2 << '\n';
    std::cout << "After Memory address for 'squadSelected' " << &squadSelected << '\n'; // 0x7ffd6e428380
}

Soldier* getSoldierById(std::string id, std::vector<Soldier> &squad){
    auto it = std::find_if(squad.begin(), squad.end(), [id](Soldier &obj){
        return obj.getId() == id;
    });
    return it != squad.end() ? &(*it) : nullptr;
}

std::vector<Soldier>& selectSquad(
    std::vector<Soldier> &squadVector1,
    std::vector<Soldier> &squadVector2,
    void (*myFunc)(std::vector<Soldier> &soldiersVector)) {
    
    std::vector<Soldier> *ptr = nullptr;
    char squadSelect;
    
    do {
        std::cout << '\n';
        std::cout << "Select Squad: " << '\n';
        std::cout << "1.) Alpha Squad" << '\n';
        std::cout << "2.) Bravo Squad" << '\n';
        std::cout << '\n';
        std::cin >> squadSelect;

        if(squadSelect == '1') {
            myFunc(squadVector1);
            ptr = &squadVector1;
        } else if(squadSelect == '2') {
            myFunc(squadVector2);
            ptr = &squadVector2;
        } else {
            std::cout << '\n';
            std::cout << "//////////////////////// \n";
            std::cout << "Invalid Entry. Try again " << '\n';
            std::cout << "//////////////////////// \n";
        }

    } while(squadSelect != '1' && squadSelect != '2');
    // Return dereferenced pointer
    // When we dereference, we get access to the actual value
    return *ptr;
}

Soldier* selectedSoldierByIdToAttack(std::vector<Soldier> &squadSelected, std::string action) {

    std::string soldierId;
    Soldier* selectedSoldier = nullptr;

    if(action == "Attacker") {
        std::cout << "Enter Soldier Id from the list above to attack \n";
    } else if (action == "Defender") {
        std::cout << "Enter Soldier Id as the target to attack\n";
    }

    std::cin >> soldierId;

    selectedSoldier = getSoldierById(soldierId, squadSelected);

    if(selectedSoldier) {
        std::cout << "\n";
        std::cout << "/////////////////////////////////////// \n";
        std::cout << "You selected the " << (action == "Attacker" ? "Attacker" : "Defender") << '\n';
        std::cout << "Name: " << selectedSoldier->getName() << '\n';
        std::cout << "Status: " << selectedSoldier->getStatus() << '\n';
        std::cout << "Health: " << selectedSoldier->getHealth() << '\n';
        std::cout << "Weapon: " << selectedSoldier->getWeapon() << '\n';
        std::cout << "/////////////////////////////////////// \n";
        std::cout << "\n";
    } else {
        std::cout << "\n";
        std::cout << "Invalid Id Entry.......\n";
        std::cout << "\n";
    }

    return selectedSoldier;
}