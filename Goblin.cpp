#include "Goblin.h"

// Default constructor
Goblin::Goblin() {
  SetName("Goblin");
  SetHealth(5);
}

// Overloaded constructor
Goblin::Goblin(string name, int hp) {
  SetName(name);
  SetHealth(hp);
}

// Defines the Goblin's special attack
int Goblin::SpecialAttack() {
  int damage = 2;
  
  cout << this->GetName() << " knaws at your ankles!" << endl;
  cout << this->GetName() << " deals " << damage << " damage!" << endl << endl;
  return damage;
}
