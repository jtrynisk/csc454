#ifndef ANIMAL_H_
#define ANIMAL_H_

#include "Creature.h"

class Animal : public Creature
{

public:
	//Constructors
	Animal(int name, int roomNum);

	std::string getClass();
	bool checkPreference(int state);
	int getName();
	int getRoom();
	void setRoom(int roomNum);

private:
	int name;
	int room;


};
#endif //PROJECT_1_ANIMAL_H
