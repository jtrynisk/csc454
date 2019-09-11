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


	std::cin >> numberOfRooms;
	Room roomList[numberOfRooms];
	PC *pc = new PC();
	std::string input;

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
		if(creatureType == 0)
		{
			roomList[assignedRoom].addCreature(pc);
			pc->setRoom(assignedRoom);
		}
		if(creatureType == 1)
		{
			roomList[assignedRoom].addAnimal(i);

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

	while(input != "exit")
	{
		int currentRoom = pc->getRoom();
		std::cout << "Please enter a command(Enter help for a list of commands): " << '\n';
		std::cin >> input;

		if(input == "move")
		{
			std::string direction = "north";
			if(roomList[currentRoom].checkMove(pc->getName(), direction))
			{
				int newRoom = roomList[currentRoom].getNeighbor(direction);
				roomList[newRoom].addCreature(pc);
				roomList[currentRoom].removeCreature(pc->getName());
			}

		}

		else if(input == "clean")
		{
			if(roomList[currentRoom].getState() == "half-dirty")
			{
				roomList[currentRoom].setState(0);
				roomList[currentRoom].reactToChangedState(pc, input);
				std::cout << "PC respect: " << pc->getRespect() << '\n';
			}
			else if(roomList[currentRoom].getState() == "dirty")
			{
				roomList[currentRoom].setState(1);
				roomList[currentRoom].reactToChangedState(pc, input);
				std::cout << "PC respect: " << pc->getRespect() << '\n';
			}
		}

		else if(input == "dirty")
		{
			if(roomList[currentRoom].getState() == "half-dirty")
			{
				roomList[currentRoom].setState(2);
				roomList[currentRoom].reactToChangedState(pc, input);
				std::cout << "PC respect: " << pc->getRespect() << '\n';
			}
			else if(roomList[currentRoom].getState() == "clean")
			{
				roomList[currentRoom].setState(1);
				roomList[currentRoom].reactToChangedState(pc, input);
				std::cout << "PC respect: " << pc->getRespect() << '\n';
			}
		}

		else if(input.find(":") != std::string::npos)
		{
				//logic for creature clean, dirty, move
		}

		else if(input == "look")
		{
			int tempRoom = pc->getRoom();
			for(int i = 0; i < numberOfRooms; i++)
			{
				if(roomList[i].roomNumber == tempRoom)
				{
					roomList[i].getNeighbors();
					roomList[i].getCreatures();
					std::cout << "Current state: " << roomList[i].getState() << '\n';
				}
			}
		}

		else if(input == "help")
		{
			std::cout << "Available commands: " << '\n';
			std::cout << "move: Move to another room input as follows move 0" << '\n';
			std::cout << "clean: Clean the room. " << '\n';
			std::cout << "dirty: Dirty the room. " << '\n';
			std::cout << "creature:clean: have a creature clean the room, example input 2:clean." << '\n';
			std::cout << "creature:dirty: have a creature dirty the room, example input 2:dirty" << '\n';
			std::cout << "creature:move: have a creature move to another room, example 2:east" << '\n';
			std::cout << "look: tells you creatures in the room and neighboring rooms." << '\n';
		}

		else if(input == "exit")
		{
			break;
		}
		else
		{
			std::cout << "Sorry command not recognized!" << '\n';
		}
	}

	delete pc;
}
