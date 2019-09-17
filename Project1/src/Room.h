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
	std::vector<Creature*> creatureList;


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
	 * removes a creature from the creature array.
	 */
	void removeCreature(Creature c);

	/**
	 * Returns all the creatures in the room.
	 */
	void getCreatures();

	/**
	 * Method that removes a creature from the vector
	 */
	void removeCreature(int name);

	/**
	 * Returns the state of the room
	 */
	std::string getState();

	/**
	 * Sets the state of the room
	 */
	void setState(int state);

	/**
	 * Checks if a creature can move to a neighbor
	 */
	bool checkMove(std::string direction);

	/**
	 * Prints a string of the neighbors for the look command
	 */
	void getNeighbors();

	/**
	 * Method to adjust PC respect based off state change.
	 */
	void reactToChangedState(PC *pc, std::string command);

	/**
	 * returns the room number
	 */
	int getRoomNumber() const {
		return roomNumber;
	}

	/**
	 * takes an int to set the roomNumber to.
	 */
	void setRoomNumber(int roomNumber) {
		this->roomNumber = roomNumber;
	}

	/**
	 * returns the amount of creatures in the room
	 */
	int getCreatureCount() const {
		return creatureCount;
	}

	/**
	 * sets the creaturecount
	 */
	void setCreatureCount(int creatureCount) {
		this->creatureCount = creatureCount;
	}

private:
	int creatureCount;

};
#endif /* ROOM_H_ */
