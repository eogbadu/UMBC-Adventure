#include "BabyDragon.h"

// Default constructor
BabyDragon::BabyDragon() {
  SetName("BabyDragon_Reucorn");
  SetHealth(10);
}

// Overloaded constructor
BabyDragon::BabyDragon(string name, int hp) {
  SetName(name);
  SetHealth(hp);
}

// Defines the Dragon's special attack
int BabyDragon::SpecialAttack() {
  int damage = 4;
  cout << this->GetName() << " breaths a cone of fire at you!" << endl;
  cout << this->GetName() << " deals " << damage << " damage!" << endl << endl;
  return damage;
}
