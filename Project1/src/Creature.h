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
	~Creature();
	int getPreference();
	void setPreference(int roomPreference);
	int getName();
	void setName(int name);
	std::string getClass();

private:
	int name;


};
#endif //PROJECT_1_CREATURE_H
