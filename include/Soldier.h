#ifndef SOLDIER_H
#define SOLDIER_H
#include <iostream>
#include <vector>

class Soldier {
    private:
        /* data */
        std::string id;
    public:
        std::string name;
        std::string status = "Alive";
        int health;
        std::string weapon;

        Soldier(std::string id, std::string name, int health, std::string weapon);
        Soldier();
        ~Soldier();

        std::string getId();
        std::string getName();
        std::string getStatus();
        std::string getWeapon();
        int getHealth();

        void setHealth(int currentHealth);
        void setStatus(std::string status);

        // Actions
        int takeDamage(int damageAmount);
        int dealDamage(std::string weapon);
        void heal(int healthAmount);
        void attackEnemy(std::string soldierId, std::string enemyId, std::vector<Soldier> &enemySquad);
};

#endif