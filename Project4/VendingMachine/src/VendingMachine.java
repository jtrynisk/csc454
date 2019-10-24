public class VendingMachine
{
    private int q, n, d, v, e, ta;

    public VendingMachine(int quarters, int nickels, int dimes, int total)
    {
        this.q = quarters;
        this.n = nickels;
        this.d = dimes;
        this.v = total;
        this.e = this.ta = 0;
    }

    public void lambda()
    {
        String output = "";
        //Add the amount of coffees we have.
        if(v >= 100)
        {
            //Loop until we don't have enough money for coffee
            while(v >= 100)
            {
                output += "coffee ";
                v -= 100;
            }
        }

        //Get the change available and add it to output
        output += "Change: " + change(false);

        //Print the output.
        System.out.println(output);

    }

    public void delta(int q, int n, int d)
    {
        timeAdvance();
        //Logic for determining which delta we are running.
        if(e == ta)
            deltaint();
        else
            deltaext();
        //Somehow deltacon?
    }

    private void deltaint()
    {
        lambda();
        change(true);
    }

    private void deltaext()
    {

    }

    private void deltacon()
    {

    }

    /**
     * Simply sets ta to 2 if totalInserted is greater than 0
     */
    private void timeAdvance()
    {
        if(v > 0)
            ta = 2;
    }

    /**
     * Create change based on what is in the machine.
     * @param flag true subtract coins, false just give the string
     * @return the string of the coins returned.
     */
    private String change(boolean flag)
    {
        String changeReturned = "";





        return changeReturned;
    }
}
