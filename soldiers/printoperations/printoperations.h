#include <vector>
#include "../soldierHeaders/soldier.h"

void printTitle();
void printSquadVector(std::vector<Soldier> &squad);
void printCommandActions();
void pressToContinue();
void printMemoryAddresses(
    std::vector<Soldier> &squad1,
    std::vector<Soldier>  &squad2,
    std::vector<Soldier>  &squadSelected);
std::vector<Soldier>& selectSquad(
    std::vector<Soldier> &squadVector1, 
    std::vector<Soldier> &squadVector2,
    void (*myFunc)(std::vector<Soldier> &soldiersVector));