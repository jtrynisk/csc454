#ifndef NPC_H_
#define NPC_H_

#include "Creature.h"

class NPC : public Creature
{
public:

	//Constructor
	NPC(int name);

	//Destructor
	~NPC();

	std::string getClass();
	int getName();
	bool checkPreference(int state);

private:
	int name;

};
#endif
