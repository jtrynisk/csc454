#ifndef NPC_H_
#define NPC_H_

#include "Creature.h"

class NPC : public Creature
{
public:

	//Constructor
	NPC(int name, int roomNum);

	//Destructor
	~NPC();

	/**
	 * Returns the string "NPC"
	 */
	std::string getClass();

	/**
	 * returns the name of the creature.
	 */
	int getName();

	/**
	 * checks if the state passed to it mathes NPC's preference.
	 */
	bool checkPreference(int state);

	/**
	 * returns the room the NPC is in.
	 */
	int getRoom();

	/**
	 * Sets the room the NPC is in.
	 */
	void setRoom(int roomNum);

private:
	int name;
	int roomNum;

};
#endif
