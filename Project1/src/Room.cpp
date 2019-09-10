//Class the defines a room object
#include "Room.h"
#include <iostream>

const int ROOM_LIMIT = 10;

Room::Room()
{
	northNeighbor = -1;
	southNeighbor = -1;
	westNeighbor = -1;
	eastNeighbor = -1;
	creatureCount = 0;
	state = 0, roomNumber = 0, npcCount = 0, animalCount = 0;
}

Room::Room(int roomState, int north, int south, int east, int west, int number)
{
	state = roomState;
	northNeighbor = north;
	southNeighbor = south;
	westNeighbor = west;
	eastNeighbor = east;
	creatureCount = 0, npcCount = 0, animalCount = 0;
	roomNumber = number;
}

Room::~Room()
{
	creatureList.clear();
}

int Room::getNeighbor(std::string neighborDirection)
{
	if(neighborDirection == "north")
	{
		return northNeighbor;
	}
	else if(neighborDirection == "south")
	{
		return southNeighbor;
	}
	else if(neighborDirection == "west")
	{
		return westNeighbor;
	}
	else if(neighborDirection == "east")
	{
		return eastNeighbor;
	}
	return -1;
}

void Room::setNeighbor(std::string neighborDirection, int neighborNumber)
{
	if(neighborDirection == "north")
		{
			northNeighbor = neighborNumber;
		}
	else if(neighborDirection == "south")
		{
			southNeighbor = neighborNumber;
		}
	else if(neighborDirection == "west")
		{
			westNeighbor = neighborNumber;
		}
	else if(neighborDirection == "east")
		{
			eastNeighbor = neighborNumber;
		}
}

void Room::addCreature(Creature *c)
{
	if(creatureCount < ROOM_LIMIT)
	{
		creatureList.push_back(c);
		creatureCount++;
	}
	else
	{
		std::cout << "Sorry room " << roomNumber << " is full.";;\
	}
}

void Room::addAnimal(Animal *a)
{
	if(creatureCount < ROOM_LIMIT)
	{
		creatureList.push_back(a);
		creatureArray[creatureCount] = a;
		creatureCount++;
	}
	else
	{
		std::cout << "Sorry room " << roomNumber << " is full.";;\
	}
}

void Room::addAnimal(int name)
{
	if(creatureCount < ROOM_LIMIT)
	{
		creatureList.push_back(new Animal(name));
		creatureCount++;
	}
	else
	{
		std::cout << "Sorry room " << roomNumber << " is full.";;\
	}
}

void Room::addNPC(NPC *npc)
{
	if(creatureCount < ROOM_LIMIT)
	{
		creatureList.push_back(npc);
		creatureArray[creatureCount] = npc;
		creatureCount++;
	}
	else
	{
		std::cout << "Sorry room " << roomNumber << " is full.";;\
	}
}

void Room::addNPC(int name)
{
	if(creatureCount < ROOM_LIMIT)
	{
		creatureList.push_back(new NPC(name));
		creatureCount++;
	}
	else
	{
		std::cout << "Sorry room " << roomNumber << " is full.";;\
	}
}

void Room::addPC(PC pc)
{
	if(creatureCount < ROOM_LIMIT)
	{
		//this->creatureList[creatureCount++] = &pc;
	}
	else
	{
		std::cout << "Sorry too many creatures in room " << roomNumber << "." << '\n';
	}
}

void Room::getCreatures()
{

	for (int i = 0; i < creatureCount; i++)
	{
		std::cout << creatureList.at(i)->getClass() << " " << creatureList.at(i)->getName() << '\n';

	}
}

std::string Room::getState()
{
	if(state == 0)
	{
		return "clean";
	}
	if(state == 1)
	{
		return "half-dirty";
	}
	if(state == 2)
	{
		return "dirty";
	}
	return "none";
}

void Room::setState(int state)
{
	this->state = state;
}
