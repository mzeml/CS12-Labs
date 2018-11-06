#ifndef WARRIOR_H
#define WARRIOR_H

#include "Character.h"

class Warrior : public Character
{
    private:
    string ally;
    public:
    Warrior(const string &name, double health, double attackStrength, string allegiance);
    void attack(Character & opp);
    string getAllegiance();
};
#endif