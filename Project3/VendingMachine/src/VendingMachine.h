#ifndef VENDINGMACHINE_H_
#define VENDINGMACHINE_H_

#include <string>

class VendingMachine
{

public:

	int quarters, nickels, dimes, total, numCoffees;
	std::string output;
	bool changeButton;
	bool coffeeDispensed;
	double totalInserted;

	VendingMachine(int q, int n, int d, bool changeButton);

	void processInput(int q, int n, int d, bool buttonPressed);

	std::string lambda();

	void delta(int q, int n, int d, bool buttonPressed);

	std::string change(bool flag);

private:


};

#endif /* VENDINGMACHINE_H_ */
