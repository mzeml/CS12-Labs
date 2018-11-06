#include <iostream>
#include <typeinfo> 
using namespace std;

#include "Warrior.h"
#include "Elf.h"
#include "Wizard.h"

int main() {

    Warrior w1("Arthur", 100, 5, "King George");
    Warrior w2("Jane", 100, 6, "King George");
    Warrior w3("Bob", 100, 4, "Queen Emily");
    Elf e1("Raegron", 100, 4, "Sylvarian");
    Elf e2("Cereasstar", 100, 3, "Sylvarian");
    Elf e3("Melimion", 100, 4, "Valinorian");
    Wizard wz1("Merlin", 100, 5, 10);
    Wizard wz2("Adali", 100, 5, 8);
    Wizard wz3("Vrydore", 100, 4, 6);
    e1.attack(w1);
    cout << endl;
    e1.attack(e2);
    cout << endl;
    w2.attack(w1);
    cout << endl;
    w3.attack(w1);
    cout << endl;
    wz1.attack(wz2);
    cout << endl;
    wz1.attack(wz3);
    cout << endl;

    return 0;
}
/*
Elf Raegron shoots an arrow at Arthur --- TWANG!!
Arthur takes 4 damage.

Elf Raegron does not attack Elf Cereasstar.
They are both members of the Sylvarian family.

Warrior Jane does not attack Warrior Arthur.
They share an allegiance with King George.

Warrior Bob attacks Arthur --- SLASH!!
Arthur takes 4 damage.

Wizard Merlin attacks Adali --- POOF!!
Adali takes 6.25 damage.

Wizard Merlin attacks Vrydore --- POOF!!
Vrydore takes 8.33333 damage.
*/