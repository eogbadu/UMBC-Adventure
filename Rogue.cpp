#include "Rogue.h"

// Default Constructor
Rogue::Rogue() {
  SetName("Rogue_Reucorn");
  SetHealth(10);
}

// Overloaded Constructor
Rogue::Rogue(string name, int hp) {
  SetName(name);
  SetHealth(hp);
}

// Destructor
Rogue::~Rogue() {

}

// Defines the Rogue's special attack
int Rogue::SpecialAttack() {
  int max = 12;
  int min = 2;
  // Get random value between 2 and 12 for damage
  int damage = (rand() % max + min);
  cout << this->GetName() << " performs a sneak attack!" << endl;
  cout << this->GetName() << " deals " << damage << " damage!" << endl << endl;
  return damage;
}
