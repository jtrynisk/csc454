#ifndef ANIMAL_H_
#define ANIMAL_H_

#include "Creature.h"

class Animal : public Creature
{

public:
	//Constructors
	Animal(int name, int roomNum);


	std::string getClass();

	/**
	 * Checks if the state passed to it matches the Animal preference.
	 */
	bool checkPreference(int state);

	/**
	 * returns the name of the creature.
	 */
	int getName();

	/**
	 * returns the name of the room.
	 */
	int getRoom();

	/**
	 * sets the room to the roomNum.
	 */
	void setRoom(int roomNum);

private:
	int name;
	int room;


};
#endif //PROJECT_1_ANIMAL_H
