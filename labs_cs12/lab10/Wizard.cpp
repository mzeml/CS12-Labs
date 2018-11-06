#include <iostream>
#include <string>
using namespace std;
#include "Wizard.h"

Wizard::Wizard(const string &name, double health, double attackStrength, int wizRank) : Character(WIZARD, name, health, attackStrength), rank(wizRank)
{
    this->name = name;
    this->health = health;
    this->attackStrength = attackStrength;
    rank = wizRank;
}
int Wizard::getRank()
{
    return rank;
}
void Wizard::attack(Character & opp)
{

    
    double totalAttack = 0.0;
    
    if(opp.getType() == WIZARD)
    {
      Wizard &oppt = dynamic_cast<Wizard &>(opp);
      totalAttack = attackStrength*(static_cast<double>(getRank()) / static_cast<double>(oppt.getRank()));
      //cout << totalAttack << endl;
      oppt.setHealth(oppt.getHealth() - totalAttack);
      //cout << endl;
    }
    else
    {
        totalAttack = attackStrength;
        opp.setHealth(static_cast<double>(opp.getHealth()) - attackStrength);
    }
    cout << "Wizard " << getName() << " attacks " << opp.getName() << " --- POOF!!" << endl;
    cout << opp.getName() << " takes " << totalAttack << " damage." << endl;
    //cout << endl;

}


