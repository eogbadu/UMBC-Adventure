#include "Paladin.h"

// Default Constructor
Paladin::Paladin() {
  SetName("Paladin_reucorn");
  SetHealth(10);
}

// Overloaded Constructor
Paladin::Paladin(string name, int hp) {
  SetName(name);
  SetHealth(hp);
}

// Destructor
Paladin::~Paladin() {

}

// Defines the Paladin's special attack 
int Paladin::SpecialAttack() {
  int max = 8;
  int min = 1;

  // Get random value between 1 and 8 for damage
  int damage = (rand() % max + min);
  cout << this->GetName() << " uses smite evil!" << endl;
  cout << this->GetName() << " deals " << damage << " damage!" << endl << endl;
  return damage;
}
