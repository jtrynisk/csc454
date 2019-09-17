#ifndef PC_H_
#define PC_H_

#include "Creature.h"

class PC : public Creature
{

public:

	//Constructor
	PC();

	//Destructor
	~PC();

	/**
	 * returns the current respect of the PC
	 */
	int getRespect();

	/**
	 * decreases respect by one
	 */
	void decrementRespect();

	/**
	 * increases respect by one
	 */
	void incrementRespect();

	/**
	 * change respect by the change
	 */
	void changeRespect(int change);

	/**
	 * set the room the PC is in.
	 */
	void setRoom(int roomNum);

	/**
	 * returns the name the room is in.
	 */
	int getRoom();

	/**
	 * returns the string "PC"
	 */
	std::string getClass();


private:

	int name;
	int respect;
	int roomNum;


};
#endif /* PC_H_ */
