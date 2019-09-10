#ifndef ROOM_H_
#define ROOM_H_

#include <string>
#include <vector>
#include "Creature.h"
#include "Animal.h"
#include "NPC.h"
#include "PC.h"

class Room
{

public:

	int state;
	int roomNumber;
	int northNeighbor;
	int southNeighbor;
	int eastNeighbor;
	int westNeighbor;

	//Constructor
	Room();
	Room(int state, int northNeighbor, int southNeighbor, int eastNeighbor, int westNeighbor, int roomNumber);

	//Destructor
	~Room();

	void addAnimal(int name);
	void addNPC(int name);

	//Public methods
	/**
	 * Returns the integer of the neighbor given the direction.
	 */
	int getNeighbor(std::string neighborDirection);

	/**
	 * Sets the neighbor given the direction, and the number of the room for the
	 * neighbor being set
	 */
	void setNeighbor(std::string neighborDirection, int neighborNumber);

	/**
	 * Adds creature to the creature vector
	 */
	void addCreature(Creature *c);

	/**
	 * Method to add an animal to the creature vector
	 */
	void addAnimal(Animal *a);

	/**
	 * Adds an NPC to the room given it ins't full, adds the animal to creature Array
	 */
	void addNPC(NPC *npc);

	/**
	 * Adds the pc to the room
	 */
	void addPC(PC pc);

	/**
	 * removes a creature from the creature array.
	 */
	void removeCreature(Creature c);

	/**
	 * Returns all the creatures in the room.
	 */
	void getCreatures();

	/**
	 * Returns the state of the room
	 */
	std::string getState();

	/**
	 * Sets the state of the room
	 */
	void setState(int state);

private:
	int creatureCount;
	int animalCount;
	int npcCount;
	std::vector<Creature*> creatureList;
	Creature* creatureArray[10];

};
#endif /* ROOM_H_ */
