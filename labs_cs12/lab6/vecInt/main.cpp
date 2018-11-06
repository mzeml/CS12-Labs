#include <iostream>
#include <stdexcept>

#include "IntVector.h"

using namespace std;

int main()
{
    IntVector Vec1;
    IntVector Vec2(2, 3);
    
    cout << Vec2.at(1) << endl;
    cout << Vec2.size() << endl;
    cout << Vec2.capacity() << endl;
    cout << Vec2.empty() << endl;
    //cout << Vec1 << endl;
    cout << Vec2.at(4) << endl;
    
    
    return 0;
}