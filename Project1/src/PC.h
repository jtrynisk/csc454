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

private:

	int respect;


};
#endif /* PC_H_ */
