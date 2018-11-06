#include <iostream>
using namespace std;
#include "Character.h"

Character::Character(CharType type, const string &name, double health, double attackStrength)
{
    this->type = type;
    this->name = name;
    this->health = health;
    this->attackStrength = attackStrength;
}
CharType Character::getType() const
{
    return type;
}
const string & Character::getName() const
{
    return name;
}
int Character::getHealth() const
{
    return static_cast<int>(health);
}
void Character::setHealth(double h)
{
    health = h;
}
bool Character::isAlive() const
{
    if(getHealth() > 0)
    {
        return true;
    }
    return false;
}