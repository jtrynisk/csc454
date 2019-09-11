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

	int getRespect();
	void decrementRespect();
	void incrementRespect();
	void changeRespect(int change);
	void setRoom(int roomNum);
	int getRoom();
	std::string getClass();


private:

	int name;
	int respect;
	int roomNum;


};
#endif /* PC_H_ */
