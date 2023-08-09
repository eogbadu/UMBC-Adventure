#include "Skeleton.h"

// Default constructor
Skeleton::Skeleton() {
  SetName("Skeleton");
  SetHealth(7);
}

// Overloaded constructor
Skeleton::Skeleton(string name, int hp) {
  SetName(name);
  SetHealth(hp);
}

//Defines the Skeleton's special attack
int Skeleton::SpecialAttack() {
  int damage = 1;
  cout << this->GetName() << " bashes you with it's owm arm!" << endl;
  cout << this->GetName() << " deals " << damage << " damage!" << endl << endl;
  return damage;
}
