/**
 * The PC class that will hold the respect
 */

#include "PC.h"
#include <iostream>

using namespace std;

PC::PC()
{
	this->respect = 40;
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

int PC::getRespect()
{
	return respect;
}
