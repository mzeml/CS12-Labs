#include "Distance.h"
#include <iostream>
#include <cmath>

using namespace std;

Distance::Distance()
{
    feet = 0;
    inches = 0.0;
    return;
}
Distance::Distance(unsigned ft, double in)
{
    feet = ft;
    inches = in;
    init();
    return;
}
Distance::Distance(double in)
{
    feet = 0;
    inches = in;
    init();
    return;
}
unsigned Distance::getFeet() const
{
    return feet;
}
double Distance::getInches() const
{
    return inches;
}
double Distance::distanceInInches() const
{
    double totalInches = 0.0;
    
    totalInches = (static_cast<double>(feet) * 12) + inches;
    
    return totalInches;
}
double Distance::distanceInFeet() const
{
    double inchesToFeet = 0.0;
    
    inchesToFeet = (inches / 12);
    
   return static_cast<double>(feet) + inchesToFeet;
}
double Distance::distanceInMeters() const
{
    double tempInches = 0.0;
    double tempFeet = 0.0;
    
    tempInches = inches * 0.0254;
    
    tempFeet = (static_cast<double>(feet) * 12) * 0.0254;
    
    return tempFeet + tempInches;
}
const Distance Distance::operator+(const Distance &rhs) const
{
    return Distance(feet + rhs.feet, inches + rhs.inches);
}
const Distance Distance::operator-(const Distance &rhs) const
{
    return Distance(abs(distanceInInches() - rhs.distanceInInches()));
}
ostream & operator<<(ostream &out, const Distance &rhs)
{
    out << rhs.feet << "\' " << rhs.inches << "\"";
    return out;
}
void Distance::init()
{
    if(feet < 0)
    {
       feet = abs(feet); //Don't forget to cast to int
    }
    if(inches < 0)
    {
        inches = abs(inches);
    }
    if (inches >= 12)
    {
        while(inches >= 12)
        {
            ++feet;
           inches -= 12;
        }
    }
    return;
}