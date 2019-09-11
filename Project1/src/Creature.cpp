//Abstract class for the PC, Animals and NPC's

#include "Creature.h"
#include <iostream>

using namespace std;

Creature::Creature()
{
	preference = DIRTY;
	this->name = 0;
}

//Constructor
Creature::Creature(int name)
{
	preference = DIRTY;
	this->name = name;
//	this->roomAssignment = room;
};
//Destructor
Creature::~Creature(){};


int Creature::getPreference()
    {
    	return preference;
    }

void  Creature::setPreference(int roomPreference)
    {
    	preference = roomPreference;
    }

int Creature::getName()
{
	return name;
}

void Creature::setName(int name)
{
	this->name = name;
}

std::string Creature::getClass()
{
	return "Creature";
}

bool Creature::checkPreference(int state)
{
	if(state == preference || state == 1)
	{
		return true;
	}
	return false;
}
