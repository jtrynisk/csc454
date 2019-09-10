//A class that will define a creature
#include "Animal.h"
#include "Creature.h"
#include <iostream>

Animal::Animal(int name)
{
	this->name = name;
	this->setPreference(CLEAN);
}

std::string Animal::getClass()
{
	return "Animal";
}

int Animal::getName()
{
	return name;
}
Animal::~Animal(){}

