#include <iostream>
using namespace std;
#include "Warrior.h"
#include <string>

Warrior::Warrior(const string &name, double health, double attackStrength, string allegiance) : Character(WARRIOR, name, health, attackStrength), ally(allegiance)
{
    this->name = name;
    this->health = health;
    this->attackStrength = attackStrength;
    ally = allegiance;
}
string Warrior::getAllegiance()
{
    return ally;
}
void Warrior::attack(Character & opp)
{
    
    if(opp.getType() == WARRIOR)
    {
        Warrior &oppt = dynamic_cast<Warrior &>(opp);
        if(oppt.getAllegiance() == getAllegiance())
        {
            cout << "Warrior " << getName() << " does not attack Warrior " << oppt.getName() << "." << endl;
            cout << "They share an allegiance with " << getAllegiance() << "." << endl;
            //cout << endl;
            return;
        }
    }
    
    cout << "Warrior " << getName() << " attacks " << opp.getName() << " --- SLASH!!" << endl;
    
    double totalAttack = 0.0;
    
    totalAttack = attackStrength*(health/MAX_HEALTH);
    
    opp.setHealth(static_cast<double>(opp.getHealth()) - totalAttack);
    
    cout << opp.getName() << " takes " << totalAttack << " damage." << endl;
    //cout << endl;
}
//Ally check

//Warrior Dammage


