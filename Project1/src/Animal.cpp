//A class that will define a creature
#include "Animal.h"
#include "Creature.h"
#include <iostream>

Animal::Animal(string name)
{
	this->name = name;
	this->setPreference(CLEAN);
}

std::string Animal::getClass()
{
	return "Animal";
}

std::string Animal::getName()
{
	return name;
}
Animal::~Animal(){}

