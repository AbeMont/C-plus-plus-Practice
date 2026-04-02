#include <vector>
#include <algorithm>
#include "Soldier.h"

void printTitle();
void printSquadVector(std::vector<Soldier> &squad);
void printCommandActions();
void pressToContinue();
Soldier* getSoldierById(std::string id, std::vector<Soldier> &squad);
void printMemoryAddresses(
    std::vector<Soldier> &squad1,
    std::vector<Soldier>  &squad2,
    std::vector<Soldier>  &squadSelected);
std::vector<Soldier>& selectSquad(
    std::vector<Soldier> &squadVector1, 
    std::vector<Soldier> &squadVector2,
    void (*myFunc)(std::vector<Soldier> &soldiersVector));
Soldier* selectedSoldierByIdForEngagement(std::vector<Soldier>  &squadSelectedToAttack, std::string action);
void engagementBattle(Soldier& attacker, Soldier& target);