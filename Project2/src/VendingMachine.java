import java.math.BigDecimal;
import java.math.RoundingMode;
import java.text.DecimalFormat;

public class VendingMachine
{
    DecimalFormat format = new DecimalFormat("##.##");
    private int quarters, nickels, dimes, total, numCoffees = 0;
    private String output = "";
    private double totalInserted;
    private boolean changeButton;
    private boolean coffeeDispensed;

    /**
     * Constructs the vending machine state
     * @param q
     *          initial amount of quarters.
     * @param n
     *          inital amount of nickels.
     * @param d
     *          initial amount of dimes.
     * @param changeButton
     *          if the change button is pressed.
     */
    public VendingMachine(int q, int n, int d, boolean changeButton)
    {
        this.quarters = q;
        this.nickels = n;
        this.dimes = d;
        this.changeButton = changeButton;
    }

    /**
     * Processes input given from the command line.
     * @param q
     *          amount of quarters given
     * @param n
     *          amount of nickels given
     * @param d
     *          amount of dimes given
     * @param buttonPressed
     *          boolean for if change button is pressed
     */
    public void processInput(int q, int n, int d, boolean buttonPressed)
    {
        String output = "";
        output = lambda();
        System.out.println(output);
        delta(q, n, d, buttonPressed);
    }

    /**
     * Gives the output based on the current state of the machine
     * @return
     *          returns the output string.
     */
    private String lambda()
    {
        output = "";
        boolean flag = true;
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
            try {
                output += ("Change " + change(false));
            }catch(SimulationException e)
            {
                System.out.println("Sorry not enough change please contact management");
            }
        }
        if(flag)
        {
            output += "Nothing";
        }
        return output;
    }

    /**
     * Takes in from input and changes the state of the vending machine
     * @param q
     *          quarters given
     * @param n
     *          nickels given
     * @param d
     *          dimes given
     * @param buttonPressed
     *          bool for if the change button is pressed
     */
    private void delta(int q, int n, int d, boolean buttonPressed)
    {

        quarters += q;
        nickels += n;
        dimes += d;
        changeButton = buttonPressed;
        totalInserted += (q * .25) + (n * .05) + (d * .1);
        if(totalInserted >= 1.00)
        {
            coffeeDispensed = true;
            while(totalInserted >= 1)
            {
                numCoffees++;
                totalInserted -= 1;
            }
        }
        if(changeButton) {
            try {
                change(true);
            } catch (SimulationException e) {
                System.out.println("Insufficient change please contact management.");
                e.printStackTrace();
                System.exit(1);
            }
        }
    }

    /**
     * Calculates the change based off the total inserted during the process input
     *
     * @throws SimulationException
     *          if not enough change is in the machine an exception is thrown.
     */
    private String change(boolean flag) throws SimulationException
    {
        String changeReturned = "";
        double change = totalInserted % 100;
        BigDecimal bd = new BigDecimal(change).setScale(2, RoundingMode.HALF_UP);
        change = bd.doubleValue();
        double numQ = 0, numD = 0, numN = 0;
        if(change % .25 == 0)
        {
            numQ = change / .25;
        }
        if(numQ > quarters)
        {
            throw new SimulationException("Quarters");
        }
        change = change - (numQ * .25);
        if(change % .10 == 0)
        {
            numD = change / .10;
        }
        if(numD > dimes)
        {
            throw new SimulationException("Dimes");
        }
        change = change - (numD * .10);
        if(change % .05 == 0)
        {
            numN = change /.05;
        }
        if(numN > nickels)
        {
            throw new SimulationException("Nickels");
        }
        change = change - (numN * .05);
        if(change != 0)
        {
            throw new SimulationException("Incorrect Change");
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
            for(int i = 0; i < changeReturned.split("").length; i++)
            {
                if (changeReturned.split("")[i] == "q")
                {
                    numQ--;
                }
                if (changeReturned.split("")[i] == "n")
                {
                    numN--;
                }
                if (changeReturned.split("")[i] == "d")
                {
                    numD--;
                }

            }
        }
        return changeReturned;
    }
}
