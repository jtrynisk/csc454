import java.math.BigDecimal;
import java.math.RoundingMode;
import java.text.DecimalFormat;

public class VendingMachine
{
    DecimalFormat format = new DecimalFormat("##.##");
    private int quarters, nickels, dimes, total, numCoffees = 0;
    private String changeReturned = "", output = "";
    private double totalInserted;
    private boolean changeButton;
    private boolean coffeeDispensed;

    public VendingMachine(int q, int n, int d, boolean changeButton)
    {
        this.quarters = q;
        this.nickels = n;
        this.dimes = d;
        this.changeButton = changeButton;
    }



    public void processInput(int q, int n, int d, boolean buttonPressed)
    {
        String output = "";
        output = lambda();
        System.out.println(output);
        delta(q, n, d, buttonPressed);
    }

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
            output += ("Change " + changeReturned);
            changeReturned = "";
        }
        if(flag)
        {
            output += "Nothing";
        }
        return output;
    }

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
                change();
            } catch (SimulationException e) {
                System.out.println("Insufficient change please contact management.");
                e.printStackTrace();
                System.exit(1);
            }
        }
    }

    private void change() throws SimulationException
    {
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
    }
}
