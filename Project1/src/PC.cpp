/**
 * The PC class that will hold the respect
 */

#include "PC.h"
#include <iostream>

using namespace std;

PC::PC()
{
	this->respect = 40;
	this->name = -1;
	roomNum = -1;
}

PC::~PC(){}

void PC::decrementRespect()
{
	this->respect--;
}

void PC::incrementRespect()
{
	this->respect++;
}

void PC::changeRespect(int change)
{
	this->respect += change;
}

int PC::getRespect()
{
	return respect;
}

int PC::getRoom()
{
	return roomNum;
}

void PC::setRoom(int roomNum)
{
	this->roomNum = roomNum;
}

std::string PC::getClass()
{
	return "PC";
}
