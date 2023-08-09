#include "Wizard.h"

// Default Constructor
Wizard::Wizard() {
  SetName("Wizard_reucorn");
  SetHealth(10);
}

// Overloaded Constructor
Wizard::Wizard(string name, int hp) {
  SetName(name);
  SetHealth(hp);
}

// Destructor
Wizard::~Wizard() {

}

// Defines the Wizard's special attack
int Wizard::SpecialAttack() {
  int max = 12;
  int min = 3;
  
  // Get random value between 3 and 12 for damage
  int damage = (rand() % max + min);
  cout << this->GetName() << " casts magic missle!" << endl;
  cout << this->GetName() << " deals " << damage << " damage!" << endl << endl;
  return damage;
}
