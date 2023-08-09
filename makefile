PROJ	= proj4
CXX	= g++
CXXFLAGS	= -g -ansi -Wall

OBJECTS = Entity.o Room.o Character.o Monster.o Paladin.o Rogue.o Wizard.o Skeleton.o BabyDragon.o Goblin.o


$(PROJ): Game.o proj4.cpp $(OBJECTS)
	$(CXX) $(CXXFLAGS) Game.o $(OBJECTS) proj4.cpp -o $(PROJ)

Game.o: Game.h Game.cpp $(OBJECTS)
	$(CXX) $(CXXFLAGS) -c Game.cpp

Rogue.o: Rogue.h Rogue.cpp Character.o
	$(CXX) $(CXXFLAGS) -c Rogue.cpp

Wizard.o: Wizard.h Wizard.cpp Character.o
	$(CXX) $(CXXFLAGS) -c Wizard.cpp

Paladin.o: Paladin.h Paladin.cpp Character.o
	$(CXX) $(CXXFLAGS) -c Paladin.cpp

Goblin.o: Goblin.h Goblin.cpp Monster.o
	$(CXX) $(CXXFLAGS) -c Goblin.cpp

Skeleton.o: Skeleton.h Skeleton.cpp Monster.o
	$(CXX) $(CXXFLAGS) -c Skeleton.cpp

BabyDragon.o: BabyDragon.h BabyDragon.cpp Monster.o
	$(CXX) $(CXXFLAGS) -c BabyDragon.cpp

Monster.o: Monster.h Monster.cpp Entity.o
	$(CXX) $(CXXFLAGS) -c Monster.cpp

Character.o: Character.h Character.cpp Entity.o
	$(CXX) $(CXXFLAGS) -c Character.cpp

Entity.o: Entity.h Entity.cpp 
	$(CXX) $(CXXFLAGS) -c Entity.cpp

Room.o: Room.h Room.cpp
	$(CXX) $(CXXFLAGS) -c Room.cpp

run:
	./proj4

val1:
	valgrind ./proj4

clean:
	rm*~
