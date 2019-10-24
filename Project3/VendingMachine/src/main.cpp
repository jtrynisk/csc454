#include "VendingMachine.cpp"


int main()
{
    int q = 0, n = 0, d = 0;
    bool changeButton;
    std::string input, output;
    std::cout << "Please enter the beginning state of the vending machine: ";
    std:: cin >> input;
    char inputArr[input.length()];
    strcpy(inputArr, input.c_str());

    //Gets initial input for state of the machine
    for(unsigned i = 0; i < input.length(); i++)
    {
        if(inputArr[i] == 'q')
        {
            q++;
        }
        if(inputArr[i] == 'n')
        {
            n++;
        }
        if(inputArr[i] == 'd')
        {
            d++;
        }
    }

    //Creates the vending machine based off initial input.
    VendingMachine* vm = new VendingMachine(q, n, d, false);

    while(input != "exit")
    {
        //Reset the variables
        q = n = d = 0;
        changeButton = false;

        //Ask for input
        std::cout << "Please enter input: ";
        std::cin >> input;
        //Exit program if needed.
        if(input == "exit")
        {
            break;
        }
        char inputArr[input.length()];
        strcpy(inputArr, input.c_str());

        //Process the input
        for(unsigned i = 0; i < input.length(); i++)
        {
            if(inputArr[i] == 'q')
            {
                q++;
            }
            if(inputArr[i] == 'n')
            {
                n++;
            }
            if(inputArr[i] == 'd')
            {
                d++;
            }
            if(inputArr[i] == 'c')
            {
                changeButton = true;
            }
            if(inputArr[i] == 'w')
            {
                //Intentionally left blank
            }
        }

        //Have vending machine process the input.
        vm->processInput(q, n, d, changeButton);
    }
    delete vm;
}




