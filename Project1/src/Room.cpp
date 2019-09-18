//Class the defines a room object
#include "Room.h"
#include <iostream>

const int ROOM_LIMIT = 10;

Room roomList[10];
int numberOfRooms;

Room::Room()
{
	northNeighbor = -1;
	southNeighbor = -1;
	westNeighbor = -1;
	eastNeighbor = -1;
	creatureCount = 0;
	state = 0, roomNumber = 0;
}

Room::Room(int roomState, int north, int south, int east, int west, int number)
{
	state = roomState;
	northNeighbor = north;
	southNeighbor = south;
	westNeighbor = west;
	eastNeighbor = east;
	creatureCount = 0;
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
		std::cout << "East neighbor is " << eastNeighbor << ". \n";
	}
	if(westNeighbor != -1)
	{
		std::cout << "West neighbor is " << westNeighbor << ". \n";
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
		//creatureArray[creatureCount] = a;
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
		creatureList.push_back(new Animal(name, this->roomNumber));
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
		//creatureArray[creatureCount] = npc;
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
		creatureList.push_back(new NPC(name, roomNumber));
		creatureCount++;
	}
	else
	{
		std::cout << "Sorry room " << roomNumber << " is full.";;\
	}
}

void Room::removeCreature(int name)
{
	for(unsigned i = 0; i < creatureList.size(); i++)
	{
		if(creatureList.at(i)->getName() == name)
		{
			delete creatureList.at(i);
			//creatureList.erase(creatureList.begin() + i);
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

bool Room::checkMove(std::string direction)
{
	if(direction == "north")
	{
		if(northNeighbor == -1)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	else if(direction == "south")
	{
		if(southNeighbor == -1)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	else if(direction == "east")
	{
		if(eastNeighbor == -1)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	else if(direction == "west")
	{
		if(westNeighbor == -1)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	return false;
}

void Room::reactToChangedState(PC *pc, std::string command)
{
	std::vector<int> toRemove;
	for(unsigned i = 0; i < creatureList.size(); i++)
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
				std::cout << creatureList.at(i)->getName() << " growls at you." << '\n';
				pc->decrementRespect();
				bool successfulMove = 0x00;
				std::string directions[] = {"north", "south", "east", "west"};
				for(int j = 0; j < 4; j++)
				{
					int attemptedMove = std::rand() % 4;
					if(checkMove(directions[attemptedMove]))
					{
						successfulMove = true;
						int newRoom = getNeighbor(directions[attemptedMove]);
						std::cout << creatureList.at(i)->getName() << " leaves to the " << directions[attemptedMove] << "." << '\n';
						for(int k = 0; k < numberOfRooms; k++)
						{
							if(roomList[k].getRoomNumber() == newRoom)
							{
								roomList[k].addAnimal(creatureList.at(i)->getName());
								if(roomList[k].getState() == "dirty")
								{
									roomList[k].setState(1);
								}
								removeCreature(creatureList.at(i)->getName());
							}
						}
					}
				}
				if(!successfulMove)
				{
					std::cout << creatureList.at(i)->getName() << " drills a hole through the ceiling and leaves." << '\n';
					toRemove.push_back(creatureList.at(i)->getName());
					for(unsigned k = 0; k < creatureList.size(); k++)
					{
						if(creatureList.at(k)->getClass() == "Animal")
						{
							pc->decrementRespect();
							std::cout << creatureList.at(k)->getName() << " growls at you." << '\n';
						}
					}
				}
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
			if(state == 0)
			{
				std::cout << creatureList.at(i)->getName() << " grumbles at you." << '\n';
				pc->decrementRespect();
				bool successfulMove = 0x00;
				std::string directions[] = {"north", "south", "east", "west"};
				for(int j = 0; j < 4; j++)
				{
					int attemptedMove = std::rand() % 4;
					if(checkMove(directions[attemptedMove]))
					{
						successfulMove = true;
						int newRoom = getNeighbor(directions[attemptedMove]);
						for(int k = 0; k < numberOfRooms; k++)
						{
							if(roomList[k].getRoomNumber() == newRoom)
							{
								std::cout << creatureList.at(i)->getName() << " leaves to the " << directions[attemptedMove] << "." << '\n';
								roomList[k].addNPC(creatureList.at(i)->getName());
								if(roomList[k].getState() == "clean")
								{
									roomList[k].setState(1);
								}
								toRemove.push_back(creatureList.at(i)->getName());
							}
						}
					}
				}
				if(!successfulMove)
				{
					std::cout << creatureList.at(i)->getName() << " drills a hole through the ceiling and leaves." << '\n';
					removeCreature(creatureList.at(i)->getName());
					for(unsigned k = 0; k < creatureList.size(); k++)
					{
						if(creatureList.at(k)->getClass() == "NPC")
						{
							pc->decrementRespect();
							std::cout << creatureList.at(k)->getName() << " grumbles at you." << '\n';
						}
					}
				}
			}
		}
	}

	for(unsigned i = 0; i < toRemove.size(); i++)
	{
		removeCreature(toRemove.at(i));
	}
}
