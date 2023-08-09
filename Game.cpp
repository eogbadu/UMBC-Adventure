#include "Game.h"// Default Constructor
Game::Game() {
  string fileName;

  // Get filename from user and load the map
  cout << "Enter a file name: ";
  cin >> fileName;
  LoadMap(fileName);

  // Output welcome message
  cout << "Welcome to UMBC Adventure!" << endl;

  // Create character from user input
  CharacterCreation();

  
  // Set player variables
  m_numRests = NUM_RESTS;
  m_numSpecial = NUM_SPECIAL;
}

// Overloaded Constructor
Game::Game(string fileName) {
  // Load map using string variable
  LoadMap(fileName);

  // Output welcome message
  cout << "Welcome to UMBC Adventure!" << endl;

  // Create character from user input 
  CharacterCreation();

  // Set player variables
  m_numRests = NUM_RESTS;
  m_numSpecial = NUM_SPECIAL;
}

// Destructor
Game::~Game() {

  delete m_myCharacter;
  m_myCharacter = NULL;

  delete m_curMonster;
  m_curMonster = NULL;
}

// Loads the map from a textfile
void Game::LoadMap(string fileName) {

  // Declare variables
  string id;
  string name;
  string desc;
  string north;
  string east;
  string south;
  string west;

  
  ifstream inStream;
  inStream.open(fileName);
  
  if(inStream.fail()) {
    cout << "File failed to load.\n";
  }
  else {
    while (getline(inStream, id, '|')) {
      
      getline(inStream, name, '|');
      getline(inStream, desc, '|');
      getline(inStream, north, '|');
      getline(inStream, east, '|');
      getline(inStream, south, '|');
      getline(inStream, west, '\n');
      west = west.substr(0, west.size() - 1);
   
      Room *tempRoom = new Room(stoi(id), name, desc, stoi(north), stoi(east), stoi(south), stoi(west));
      
      m_myMap.push_back(tempRoom);
    }
  }

  
  inStream.close();  
}

// Used to create dynamic character from user input
void Game::CharacterCreation() {

  string name;
  int type;
  int numTypes = 4; // Types of characters available to use

  cout << "Character Name: ";
  cin >> name;
  cout << endl << endl << "Select a class" << endl << endl;
  cout << "1. Rogue" << endl;
  cout << "2. Wizard" << endl;
  cout << "3. Paladin" << endl;
  cout << "4. No Class" << endl << endl;
  cin >> type;

  while (type < 1 || type > numTypes) {
    cout << "Class " << type << " is not an option." << endl << endl;
    cout << "Select a class" << endl << endl;
    cout << "1. Rogue" << endl;
    cout << "2. Wizard" << endl;
    cout << "3. Paladin" << endl;
    cout << "4. No Class" << endl << endl;
    cin >> type;
  }

  switch (type){
  case 1:
    m_myCharacter = new Rogue(name, ROGUE_HEALTH);
    break;
  case 2:
    m_myCharacter = new Wizard(name, WIZARD_HEALTH);
    break;
  case 3:
    m_myCharacter = new Paladin(name, PALADIN_HEALTH);
    break;
  case 4:
    m_myCharacter = new Character(name, WIZARD_HEALTH);
    break;
  default:
    m_myCharacter = new Character(name, WIZARD_HEALTH);
  }

  StartGame();
}

// Used to start the game
void Game::StartGame() {
  // Set game variables
  m_curRoom = START_ROOM;
  m_numRests = NUM_RESTS;
  m_numSpecial = NUM_SPECIAL;

  m_curMonster = RandomMonster();
  m_myMap.at(m_curRoom)->PrintRoom();

  // Get output based on type of monster in the room
  if (m_curMonster == NULL) {
    cout << endl << "It is peaceful here." << endl << endl;
  }
  else {
    string mName = m_curMonster->GetName();
       
    if (mName.compare("Skeleton") == 0) {
      cout << "A skeleton lumbers around the room." << endl << endl;
    }
    else if (mName.compare("Baby Dragon") == 0) {
      cout << "A baby dragon in on its first hunt here." << endl << endl;
    }
    else if (mName.compare("Goblin") == 0) {
      cout << "A goblin is here picking his nose." << endl << endl;
    }
  }
  
  Action();
}

// The menu in the game with choices to pick from
void Game::Action() {
  int choice;

  // If player is dead, delliver message then end game
  if (m_myCharacter->GetHealth() < 1) {
    cout << "Sorry! You Lost!" << endl << endl;

    // Delete player
    delete m_myCharacter;
    m_myCharacter = NULL;

    // Delete monster
    delete m_curMonster;
    m_curMonster = NULL;

    // Delete rooms
    for (unsigned int i = 0; i < m_myMap.size(); i++)
      {
        cout << m_myMap.size() << endl;
        delete m_myMap[i];
        m_myMap[i] = NULL;
      }
    this->m_myMap.clear();
    
    exit(1);
  }
  else {
    cout << "What would you like to do?" << endl << endl;
    cout << "1. Look" << endl;
    cout << "2. Move" << endl;
    cout << "3. Attack Monster" << endl;
    cout << "4. Rest" << endl;
    cout << "5. Check Stats" << endl;
    cout << "6. Quit" << endl;
    cin >> choice;
  
    while (( choice < 1) || (choice > 6)) {
      cout << "Invalid choice entered. Choose 1 - 6" << endl;
      cout << "What would you like to do?" << endl;
      cout << "1. Look" << endl;
      cout << "2. Move" << endl;
      cout << "3. Attack Monster" << endl;
      cout << "4. Rest" << endl;
      cout << "5. Check Stats" << endl;
      cout << "6. Quit" << endl;
      cin >> choice;
    }
  }
  switch (choice) {
  case 1:
    // Print out the room details
    m_myMap.at(m_curRoom)->PrintRoom();
    if (m_curMonster == NULL) {
      cout << endl << "It is peaceful here." << endl << endl;
    }
    else {
      string mName = m_curMonster->GetName();
      
      if (mName.compare("Skeleton") == 0) {
	cout << "A skeleton lumbers around the room." << endl << endl;
      }
      else if (mName.compare("Baby Dragon") == 0) {
	cout << "A baby dragon in on its first hunt here." << endl << endl;
      }
      else if (mName.compare("Goblin") == 0) {
	cout << "A goblin is here picking his nose." << endl << endl;
      }
    }
    Action();
    break;
  case 2:
    Move();
    break;
  case 3:
    Attack();
    break;
  case 4:
    // Check if there is a monster in the room and if rests are
    // available
    if ((this->m_numRests > 0) && (this->m_curMonster == NULL)) {
      this->m_numRests -= 1;
      m_myCharacter->SetHealth(m_myCharacter->GetHealth() + REST_HEAL);
      this->m_numSpecial = NUM_SPECIAL;
    }
    else if ((this->m_numRests > 0) && (this->m_curMonster != NULL)) {
      cout << "You can't rest with a monster here. DUH!" << endl;
    }
    else {
      cout << "You don't have any more rests" << endl;
    }
    Action();
    break;
  case 5:
    Stats();
    break;
  case 6:
    cout << "Goodbye!" << endl;
    // Delete rooms
    for (unsigned int i = 0; i < this->m_myMap.size(); i++)
      {
	cout << m_myMap.size() << endl;
	delete m_myMap[i];
	m_myMap[i] = NULL;
      }
    this->m_myMap.clear();

    // Delete player
    delete m_myCharacter;
    m_myCharacter = NULL;

    // Delete Monster
    delete m_curMonster;
    m_curMonster = NULL;
    
    exit(1);
  }
}

// Used to generate a random monster dynamically
Entity* Game::RandomMonster() {
  int monsterType = (int)(rand() % 4) + 1;
  Entity * tempMonster;
  switch (monsterType) {
  case 1:
    tempMonster = new Goblin("Goblin", GOBLIN_HEALTH);
    break;
  case 2:
    tempMonster = new Skeleton("Skeleton", SKELETON_HEALTH);
    break;
  case 3:
    tempMonster = new BabyDragon("Baby Dragon", DRAGON_HEALTH);
    break;
  case 4:
    tempMonster = NULL;
    break;
  }

  return tempMonster;
}

// Moves a player from one room to another (updates m_curRoom)
void Game::Move() {
  char choice;

  // Ask for direction and get input
  cout << "Which direction? (N E S W)" << endl;
  cin >> choice;

  while (m_myMap.at(m_curRoom)->CheckDirection(choice) == -1) {
    cout << "Which direction? (N E S W)" << endl;
    cin >> choice;
  }

  // Delete monster in room you are leaving if still alive
  if (m_curMonster != NULL) {
    delete m_curMonster;
    m_curMonster = NULL;
  }

  // Change room and generate a monster randomly
  m_curRoom = m_myMap.at(m_curRoom)->CheckDirection(choice);
  m_curMonster = RandomMonster();

  // Print room details
  m_myMap.at(m_curRoom)->PrintRoom();

  // Print what monster is doing in the room.
  if (m_curMonster == NULL) {
    cout << endl << "It is peaceful here." << endl << endl;
  }
  else {
    string mName = m_curMonster->GetName();
   
    if (mName.compare("Skeleton") == 0) {
      cout << "A skeleton lumbers around the room." << endl << endl;
    }
    else if (mName.compare("Baby Dragon") == 0) {
      cout << "A baby dragon in on its first hunt here." << endl << endl;
    }
    else if (mName.compare("Goblin") == 0) {
      cout << "A goblin is here picking his nose." << endl << endl;
    }
  }
  Action();
}

// Allows player to attack an enemy entity.
void Game::Attack() {
  int choice;
  int hp;
  int charHp = m_myCharacter->GetHealth();
  int monsHp = m_curMonster->GetHealth();
  int max = 4;
  int min = 1;

  // Check that there is a monster in the room
  if (this->m_curMonster == NULL) {
    cout << "What exactly are you trying to attack...stupid!" << endl;
  }
  else {
    while ((charHp > 0) && (monsHp > 0)) {
      // while both the player and monster are alive
      // keep fighting
      int monsterAttackType = (int)(rand() % max) + min;;

      // if specials are available to the player
      if (this->m_numSpecial > 0) {
	cout << "1. Normal Attack" << endl;
	cout << "2. Special Attack" << endl;
	
	cin >> choice;
	while ((choice != 1) && (choice != 2)) {
	  cout << "Invalid Entry" << endl << endl;
	  cout << "1. Normal Attack" << endl;
	  cout << "2. Special Attack" << endl;
	  
	  cin >> choice;
	}
      }
      else {
	// the player has no specials
	cout << "1. Normal Attack" << endl;
	
	cin >> choice;
	while (choice != 1) {
	  cout << "Invalid Entry" << endl << endl;
	  cout << "1. Normal Attack" << endl;
	  
	  cin >> choice;
	}
      }
      
      switch (choice) {
      case 1: // player chooses a normal attack
	hp = m_curMonster->GetHealth();
	hp -= m_myCharacter->Attack();
	m_curMonster->SetHealth(hp);
	
	hp = m_myCharacter->GetHealth();
	if (monsterAttackType == 1) {
	  hp -= m_curMonster->SpecialAttack();
	}
	else {
	  hp -= m_curMonster->Attack();
	}
	
	m_myCharacter->SetHealth(hp);
	break;
      case 2: // Player chooses a special attack
	if (this->m_numSpecial > 0) {
	  this->m_numSpecial -= 1;
	  hp = m_curMonster->GetHealth();
	  hp -= m_myCharacter->SpecialAttack();
	  m_curMonster->SetHealth(hp);
	  
	  hp = m_myCharacter->GetHealth();
	  if (monsterAttackType == 1) {
	    hp -= m_curMonster->SpecialAttack();
	  }
	  else {
	    hp -= m_curMonster->Attack();
	  }
	  
	  m_myCharacter->SetHealth(hp);
	  break;
	}
      }
      
      charHp = m_myCharacter->GetHealth();
      monsHp = m_curMonster->GetHealth();

      // If player is defeated
      if (charHp < 1) {
	cout << endl << "You have been defeated!" << endl;
      }
      else {
	// else output health
	cout << endl <<  m_myCharacter->GetName() << "'s health: ";
	cout << m_myCharacter->GetHealth() << endl;
      }

      // if monster is dead
      if (monsHp < 1) {
	cout << endl << "You have defeated the " << m_curMonster->GetName();
	cout << "." << endl;
	delete m_curMonster;
	m_curMonster = NULL;
	
      }
      else {
	// else output health
	cout << m_curMonster->GetName() << "'s health: ";
	cout << m_curMonster->GetHealth() << endl << endl;
      }    
      
    }
  }
  Action();
}

// Print out the player stats
void Game::Stats() {
  cout << endl << "Name: " << m_myCharacter->GetName() << endl << endl;
  cout << "HP: " << m_myCharacter->GetHealth() << endl << endl;
  cout << "Rests: " << this->m_numRests << endl << endl;
  cout << "Specials: " << this->m_numSpecial << endl << endl;

  Action();
}

