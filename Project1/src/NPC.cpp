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
