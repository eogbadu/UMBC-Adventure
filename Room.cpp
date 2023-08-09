#include "Room.h"

// Overloaded constructor
Room::Room(int id, string name, string desc, int N, int E, int S, int W) {
  m_ID = id;
  m_name = name;
  m_desc = desc;
  m_direction[0] = N;
  m_direction[1] = E;
  m_direction[2] = S;
  m_direction[3] = W;
}

// Returns the name of the room
string Room::GetName() {
  return m_name;
}

// Returns the id of the current room
int Room::GetID() {
  return m_ID;
}

// Returns the description of the current room
string Room::GetDesc() {
  return m_desc;
}

// You pass it a char (N/n, E/e, S/s, or W/w) and if that is a valid exit it
// returns the ID of the room in that direction
int Room::CheckDirection(char myDirection) {
  switch (myDirection) {
  case 'N':
  case 'n':
    return m_direction[0];
    break;
  case 'E':
  case 'e':
    return m_direction[1];
    break;
  case 'S':
  case 's':
    return m_direction[2];
    break;
  case 'W':
  case 'w':
    return m_direction[3];
    break;
  default:
    return -1;
  }
}


// prints out details of the current room
void Room::PrintRoom() {
  cout <<  m_name << endl;
  cout << m_desc << endl;
  cout << "Possible Exits: ";

 
  if (m_direction[0] != -1) {
    cout << "N ";
  }
  if (m_direction[1] != -1) {
    cout << "E ";
  }
  if (m_direction[2] != -1) {
    cout << "S ";
  }
  if (m_direction[3] != -1) {
    cout << "W ";
  }
  
  cout << endl;
}
