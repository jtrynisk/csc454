#ifndef ANIMAL_H_
#define ANIMAL_H_

#include "Creature.h"

class Animal : public Creature
{

public:
	//Constructors
	Animal(int name);

	//Destructor
	~Animal();

	std::string getClass();

	int getName();

private:
	int name;


};
#endif //PROJECT_1_ANIMAL_H
