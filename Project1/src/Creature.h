#ifndef PROJECT_1_CREATURE_H
#define PROJECT_1_CREATURE_H

#include <string>

enum roomPreference
{
    CLEAN = 0,
    DIRTY = 2
};

class Creature{

public:
	int preference;

	//Constructor
	Creature();

	//Constructor
	Creature(int name);

	//Destructor
	virtual ~Creature();

	/**
	 * returns the preference of the Creature.
	 */
	int getPreference();

	/**
	 * sets the preference of the Creature.
	 */
	void setPreference(int roomPreference);

	/**
	 * returns the name of the creature.
	 */
	virtual int getName();

	/**
	 * takes a number and sets the name.
	 */
	void setName(int name);

	/**
	 * returns the type of animal overriden in each inherited class.
	 */
	virtual std::string getClass();

	/**
	 * checks if the preference matches the room it is in.
	 */
	virtual bool checkPreference(int state);

private:
	int name;


};
#endif //PROJECT_1_CREATURE_H
