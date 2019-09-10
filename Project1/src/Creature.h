#ifndef PROJECT_1_CREATURE_H
#define PROJECT_1_CREATURE_H

#include <string>

enum roomPreference
{
    CLEAN,
    DIRTY
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

private:
	int name;


};
#endif //PROJECT_1_CREATURE_H
