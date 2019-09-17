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

	std::string getClass();
	int getName();
	bool checkPreference(int state);
	int getRoom();
	void setRoom(int roomNum);

private:
	int name;
	int roomNum;

};
#endif
