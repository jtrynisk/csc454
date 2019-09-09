#ifndef ANIMAL_H_
#define ANIMAL_H_

#include "Creature.h"

class Animal : public Creature
{

public:
	//Constructors
	Animal(string name);

	//Destructor
	~Animal();

	std::string getClass();

	std::string getName();

private:
	std::string name;


};
#endif //PROJECT_1_ANIMAL_H
