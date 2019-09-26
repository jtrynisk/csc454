import java.util.*;

public class Main
{
    public static  void main(String args[])
    {
        int q = 0, n = 0, d = 0;
        boolean changeButton;
        String input, output;
        Scanner sc = new Scanner(System.in);
        System.out.print("Please enter the beggining state of the vending machine: ");
        input = sc.next();
        char[] inputArr = input.toCharArray();



        for(int i = 0; i < inputArr.length; i++)
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

        VendingMachine vm = new VendingMachine(q, n, d, false);

        while(!input.equals("exit"))
        {
            //Reset the variables
            q = n = d = 0;
            changeButton = false;

            //Ask for input
            System.out.print("Please enter input: ");
            input = sc.next();
            //Exit program if needed.
            if(input.equals("exit"))
            {
                break;
            }
            inputArr = input.toCharArray();


            //Process the input
            for(int i = 0; i < inputArr.length; i++)
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
            vm.processInput(q, n, d, changeButton);
        }

    }
}
