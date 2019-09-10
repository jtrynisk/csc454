//NPC character class extends creature
#include "Creature.h"
#include "NPC.h"
#include <iostream>

using namespace std;


NPC::NPC(int name)
{
	this->name = name;
	this->setPreference(DIRTY);
}

NPC::~NPC()
{

}

std::string NPC::getClass()
{
	return "NPC";
}

int NPC::getName()
{
	return name;
}
