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

void Room::getNeighbors()
{
	std::string tempString;
	if(northNeighbor != -1)
	{
		std::cout << "North neighbor is " <<  northNeighbor << ". \n";
	}
	if(southNeighbor != -1)
	{
		std::cout << "South neighbor is " << southNeighbor << ". \n";
	}
	if(eastNeighbor != -1)
	{
		std::cout << "East neighbor is " << northNeighbor << ". \n";
	}
	if(westNeighbor != -1)
	{
		std::cout << "West neighbor is " << northNeighbor << ". \n";
	}
	if(northNeighbor == -1 && southNeighbor == -1 && eastNeighbor == -1 && westNeighbor == -1)
	{
		std::cout << "No neighbors in this room." << '\n';
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

void Room::removeCreature(int name)
{
	for(int i = 0; i < creatureList.size(); i++)
	{
		if(creatureList.at(i)->getName() == name)
		{
			creatureList.erase(creatureList.begin() + i);
			creatureList.shrink_to_fit();
			creatureCount--;
		}
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

bool Room::checkMove(int name, std::string direction)
{
	bool canMove = false;
	for(int i = 0; i < creatureList.size(); i++)
	{
		if(creatureList.at(i)->getName() == name)
		{
			canMove = true;
		}
	}

	if(direction == "north")
	{
		if(northNeighbor == -1)
		{
			std::cout << "No room in that direction" << '\n';
			return false;
		}
		else
		{
			canMove = true;
		}
	}

	else if(direction == "south")
	{
		if(southNeighbor == -1)
		{
			std::cout << "No room in that direction" << '\n';
			return false;
		}
		else
		{
			canMove = true;
		}
	}

	else if(direction == "east")
	{
		if(eastNeighbor == -1)
		{
			std::cout << "No room in that direction" << '\n';
			return false;
		}
		else
		{
			canMove = true;
		}
	}

	else if(direction == "west")
	{
		if(westNeighbor == -1)
		{
			std::cout << "No room in that direction" << '\n';
			return false;
		}
		else
		{
			canMove = true;
		}
	}

	return canMove;
}

void Room::reactToChangedState(PC *pc, std::string command)
{
	for(int i = 0; i < creatureList.size(); i++)
	{
		if(creatureList.at(i)->getClass() == "Animal")
		{
			if(command == "clean")
			{
				std::cout << creatureList.at(i)->getName() << " licks your face." << '\n';
				pc->incrementRespect();
			}
			if(command == "dirty")
			{
				std::cout << creatureList.at(i)->getName() << " growls at you." << '\n';
				pc->decrementRespect();
			}
			if(state == 2)
			{
				char directions[] = {"n", "s", "e", "w"};
			}
		}

		if(creatureList.at(i)->getClass() == "NPC")
		{
			if(command == "clean")
			{
				std::cout << creatureList.at(i)->getName() << " grumbles at you." << '\n';
				pc->decrementRespect();
			}
			if(command == "dirty")
			{
				std::cout << creatureList.at(i)->getName() << " smiles at you." << '\n';
				pc->incrementRespect();
			}
		}
	}
}
