#include "Monster.h"

// Default constructor
Monster::Monster() {
  SetName("Monster");
  SetHealth(10);
}

// Overloaded constructor
Monster::Monster(string name, int hp) {
  SetName(name);
  SetHealth(hp);
}

// Describes attack statements for monster
int Monster::Attack() {
  int damage = 1;
  cout << this->GetName() << " deals 1 point of damage!" << endl;
  return damage;
}
