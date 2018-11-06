#include <iostream>
#include <string>
using namespace std;
#include "Elf.h"

Elf::Elf(const string &name, double health, double attackStrength, const string & familyName) : Character(ELF, name, health, attackStrength), family(familyName)
{
    this->name = name;
    this->health = health;
    this->attackStrength = attackStrength;
    family = familyName;
}
string Elf::getFamily()
{
    return family;
}
void Elf::attack(Character & opp)
{
    
    if(opp.getType() == ELF)
    {
        Elf &oppt = dynamic_cast<Elf &>(opp);
        if(oppt.getFamily() == getFamily())
        {
            cout << "Elf " << getName() << " does not attack Elf " << oppt.getName() << "." << endl;
            cout << "They are both members of the " << getFamily() << " family." << endl;
            //cout << endl;
            return;
        }
    }
      
    double totalAttack = 0.0;
    
    totalAttack = attackStrength*(static_cast<double>(health)/static_cast<double>(MAX_HEALTH));
    
    opp.setHealth(opp.getHealth() - totalAttack);

    cout << "Elf " << getName() << " shoots an arrow at " << opp.getName() << " --- TWANG!!" << endl;
    cout << opp.getName() << " takes " << totalAttack << " damage." << endl;
    //cout << endl;
}
