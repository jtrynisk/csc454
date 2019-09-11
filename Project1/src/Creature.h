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
	Creature();
	Creature(int name);
	virtual ~Creature();
	int getPreference();
	void setPreference(int roomPreference);
	virtual int getName();
	void setName(int name);
	virtual std::string getClass();
	virtual bool checkPreference(int state);

private:
	int name;
//	Room roomAssignment;


};
#endif //PROJECT_1_CREATURE_H
