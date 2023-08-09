#include "Entity.h"

// Default Constructor
// Description: Abstract class - cannot directly instantiate this class
Entity::Entity() {
  SetName("Reucorn");
  SetHealth(10);
}

// Overloaded constructor
// Description: Abstract class - cannot directly instantiate this class
Entity::Entity(string name, int health) {
  SetName(name);
  SetHealth(health);
}

// Virtual Destructor
Entity::~Entity() {
  //Left blank on purpose
}

// Used to return the name of entity 
string Entity::GetName() {
  return m_name;
}

// Used to return health of entity
int Entity::GetHealth() {
  return m_health;
}

// Sets the name of the entity
void Entity::SetName(string name) {
  m_name = name;
}

// Sets the health of the entity
void Entity::SetHealth(int health) {
  m_health = health;
}

// Prints out details of an entity
ostream& operator <<(ostream& os, Entity& entity) {
  os << "Name: " << entity.m_name << endl;
  os << "HP: " << entity.m_health << endl;

  return os << endl;
}
