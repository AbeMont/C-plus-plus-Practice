#include "Soldier.h"

Soldier::Soldier(std::string id, std::string name, int health, std::string weapon){
    this->id = id;
    this->name = name;
    this->health = health;
    this->weapon = weapon;
};

Soldier::Soldier(){};
Soldier::~Soldier(){};

std::string Soldier::getId() {
    return this->id;
};

std::string Soldier::getName() {
    return this->name;
};

std::string Soldier::getStatus() {
    return this->status;
};

std::string Soldier::getWeapon() {
    return this->weapon;
};

int Soldier::getHealth() {
    return this->health;
};

void Soldier::setHealth(int currentHealth){
    this->health = currentHealth;
};

// Actions
int Soldier::takeDamage(int damageAmount){
    int damage = health - damageAmount;
    return damage < 0 ? 0 : damage;
};

int Soldier::dealDamage(std::string weapon){
    int damage;

    if(weapon == "M4A1") damage = 25;
    if(weapon == "UMP-45") damage = 20;
    if(weapon == "AK-47") damage = 23;
    if(weapon == "PSG1") damage = 30;

    return damage;
};

void Soldier::heal(int healthAmount){
    this->setHealth(healthAmount);
};

void Soldier::attackEnemy(std::string soldierId, std::string enemyId, std::vector<Soldier> &enemySquad){
    std::cout << "Attatck action from Soldier header class \n";
};

