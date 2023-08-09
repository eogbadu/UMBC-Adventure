#include "Character.h"

// Default Constructor
Character::Character() {
  SetName("Character_Reucorn");
  SetHealth(10);
}

// Overloaded Constructor
Character::Character(string name, int health) {
  SetName(name);
  SetHealth(health);
}

// Virtual Destructor
Character::~Character() {

}

// Describes attack statements for character
int Character::Attack() {
  int max = 6;
  int min = 1;

  // Get random value between 1 and 6 for damage
  int damage = (rand() % max + min);
  cout << this->GetName() << " attacks dealing ";
  cout << damage << " damage." << endl;
  return damage;
}

// Tells player that character does not have special attack
// may be used for child class special attacks
int Character::SpecialAttack() {
  cout << "You do not have a special attack" << endl;
  return 0;
}
