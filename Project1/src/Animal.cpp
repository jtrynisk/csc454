//A class that will define a creature
#include "Animal.h"
#include <iostream>

Animal::Animal(int name, int roomNum)
{
	this->name = name;
	this->setPreference(CLEAN);
	this->room = roomNum;
}

std::string Animal::getClass()
{
	return "Animal";
}

int Animal::getName()
{
	return name;
}

bool Animal::checkPreference(int state)
{
	if(state == preference || state == 1)
	{
		return true;
	}
	return false;
}

int Animal::getRoom()
{
	return room;
}

void Animal::setRoom(int roomNum)
{
	this->room = roomNum;
}

