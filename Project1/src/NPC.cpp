//NPC character class extends creature
#include "Creature.h"
#include "NPC.h"
#include <iostream>

using namespace std;


NPC::NPC(int name, int roomNum)
{
	this->name = name;
	this->roomNum = roomNum;
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

bool NPC::checkPreference(int state)
{
	if(state == preference || state == 1)
	{
		return true;
	}
	return false;
}

void NPC::setRoom(int roomNum)
{
	this->roomNum = roomNum;
}

int NPC::getRoom()
{
	return roomNum;
}
