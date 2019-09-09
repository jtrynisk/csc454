#include "Creature.cpp"
#include "Animal.cpp"
#include "NPC.cpp"
#include "Room.cpp"
#include "PC.cpp"
#include <iostream>
#include <sstream>

using namespace std;

int main()
{
	int numberOfRooms, state, northNeighbor, southNeighbor, eastNeighbor, westNeighbor, numberOfAnimals, animalCount, npcCount;
	//initialize counts
	animalCount = 0, npcCount = 0;


	//std::vector<Room*> *roomList = new vector<Room*>;
	std::cin >> numberOfRooms;
	Room roomList[numberOfRooms];
	Creature *pc = new PC();

	//Builds each of the rooms, stores them in an array.
	for (int i = 0; i < numberOfRooms; i++)
	{
		std::scanf("%d %d %d %d %d", &state, &northNeighbor, &southNeighbor, &eastNeighbor, &westNeighbor);
		roomList[i].setNeighbor("north", northNeighbor);
		roomList[i].setNeighbor("south", southNeighbor);
		roomList[i].setNeighbor("east", eastNeighbor);
		roomList[i].setNeighbor("west", westNeighbor);
		roomList[i].setState(state);



	}

	int creatureType = 0, assignedRoom = 0;
	std::cin >> numberOfAnimals;
	for(int i = 0; i < numberOfAnimals; i++)
	{
		cin >> creatureType >> assignedRoom;
		std::cout << "Creature Type: " << creatureType << "\n";
		std::cout << "Assigned Room: " << assignedRoom << '\n';
		if(creatureType == 0)
		{
			roomList[assignedRoom].addCreature(pc);
		}
		if(creatureType == 1 && i == 0)
		{
			roomList[assignedRoom].addAnimal("Ralph");

		}
		if(creatureType == 1 && i == 1)
				{
					roomList[assignedRoom].addAnimal("Roy");

				}
		if(creatureType == 2)
		{
			roomList[assignedRoom].addNPC(i);
		}
	}

	for(int i = 0; i < numberOfRooms; i++)
	{
		std::cout << "Room state: " << roomList[i].getState() << '\n';
		std::cout << "Room's north neighbor " << roomList[i].getNeighbor("north") << '\n';
		std::cout << "Room's south neighbor " << roomList[i].getNeighbor("south") << '\n';
		std::cout << "Room's east neighbor " << roomList[i].getNeighbor("east") << '\n';
		std::cout << "Room's west neighbor " << roomList[i].getNeighbor("west") << '\n';
		roomList[i].getCreatures();
	}

	delete pc;
}
