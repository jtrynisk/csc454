#include "VendingMachine.h"
#include "SimulationException.cpp"
#include <cstring>
#include <iostream>
#include <stdio.h>


VendingMachine::VendingMachine(int q, int n, int d, bool changeButton)
{
	this->quarters = q;
	this->nickels = n;
	this->dimes = d;
	this->changeButton = changeButton;
	this->coffeeDispensed = false;
	this->totalInserted = 0.00;
	this->total = 0;
	this->numCoffees = 0;
}

void VendingMachine::processInput(int q, int n, int d, bool buttonPressed)
{
	std::string output = "";
	output = lambda();
	std::cout << output << '\n';
	delta(q, n, d, buttonPressed);
}


std::string VendingMachine::lambda()
{
	output = "";
	bool flag = true;
	if(coffeeDispensed)
	{
		flag = false;
		for(int i = 0; i < numCoffees; i++)
		{
			output += "coffee ";
		}
		coffeeDispensed = false;
		numCoffees = 0;
	}
	if(changeButton)
	{
		flag = false;
		try{
			output += ("Change " + change(false));
		}
		catch(const SimulationException& e)
		{
			std::cout << "Insufficient change please contact management.";
		}
	}
	if(flag)
	{
		output += "Nothing";
	}
	return output;
}

void VendingMachine::delta(int q, int n, int d, bool buttonPressed)
{

	quarters += q;
	nickels += n;
	dimes += d;
	changeButton = buttonPressed;
	totalInserted += ((q * 25) + (n * 05) + (d * 10));
	if(totalInserted >= 100)
	{
		coffeeDispensed = true;
		while(totalInserted >= 100)
		{
			numCoffees++;
			totalInserted -= 100;
		}
	}
	if(changeButton) {
		try {
			change(true);
		} catch (const SimulationException& e) {
			std::cout << "Insufficient change please contact management.";
		}
	}
}


std::string VendingMachine::change(bool flag)
{
	std::string changeReturned = "";
	int change = totalInserted;
	double numQ = 0, numD = 0, numN = 0;
	if(change % 25 == 0)
	{
		numQ = change / 25;
	}
	if(numQ > quarters)
	{
		throw(SimulationException("Quarters", -1, -1));
	}
	change = change - (numQ * 25);
	if(change % 10 == 0)
	{
		numD = change / 10;
	}
	if(numD > dimes)
	{
		throw(SimulationException("Dimes", -1, -1));
	}
	change = change - (numD * .10);
	if(change % 05 == 0)
	{
		numN = change /05;
	}
	if(numN > nickels)
	{
		throw (SimulationException("Nickels", -1, -1));
	}
	change = change - (numN * 05);
	if(change != 0)
	{
		throw (SimulationException("Incorrect Change", -1, -1));
	}

	for(int i = 0; i < numQ; i++)
	{
		changeReturned += 'q';
	}

	for(int i = 0; i < numD; i++)
	{
		changeReturned += 'd';
	}

	for(int i = 0; i < numN; i++)
	{
		changeReturned += 'n';
	}

	if(flag)
	{
		int length = changeReturned.length();
		char changeArr[length + 1];
		strcpy(changeArr, changeReturned.c_str());
		for(int i = 0; i < length; i++)
		{
			if (changeArr[i]  == 'q')
			{
				numQ--;
			}
			if (changeArr[i] == 'n')
			{
				numN--;
			}
			if (changeArr[i] == 'd')
			{
				numD--;
			}

		}
	}
	return changeReturned;
}

