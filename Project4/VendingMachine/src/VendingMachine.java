public class VendingMachine
{
    private int q, n, d, v;
    double e, ta;

    public VendingMachine()
    {
        this.q = 0;
        this.n = 0;
        this.d = 0;
        this.v = 0;
        this.e = this.ta = 0;
    }

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
                try{
                    change(true);
                }catch(SimulationException e)
                {
                    System.out.println("Insufficient change");
                    System.exit(1);
                }
            }
        }

        try {
            //Get the change available and add it to output
            output += "Change: " + change(true);
        }catch(SimulationException e)
        {
            System.out.println("Insufficent change");
            System.exit(1);
        }

        //Print the output.
        System.out.println(output);

    }

    public void processInput(String input, double elapsed)
    {
        if(validInput(input))
            timeAdvance();

        e = elapsed;

        //Logic for determining which delta we are running.
        if(e == ta && validInput(input)) {
            lambda();
            deltaCon(input);
        }
        else if(e == ta)
        {
            lambda();
            deltaInt(input);
        }
        else
            deltaExt(input);

    }

    private boolean validInput(String input)
    {
        if(input.equals("q") || input.equals("n") || input.equals("d"))
            return true;
        return false;
    }

    private void deltaInt(String input)
    {
        try {
            change(true);
        }catch(SimulationException e)
        {
            System.out.println("Insufficient change");
            System.exit(1);
        }
    }

    private void deltaExt(String input)
    {
        if(input.equals("q"))
        {
            q++;
            v += 25;
        }
        else if(input.equals("n"))
        {
            n++;
            v += 5;
        }
        else if(input.equals("d"))
        {
            d++;
            v += 10;
        }
    }

    private void deltaCon(String input)
    {
        deltaInt(input);
        deltaExt(input);
    }

    /**
     * Simply sets ta to 2
     */
    private void timeAdvance()
    {
        ta = 2;
    }

    /**
     * Create change based on what is in the machine.
     * @param flag true subtract coins, false just give the string
     * @return the string of the coins returned.
     */
    private String change(boolean flag) throws SimulationException
    {
        String changeReturned = "";
        int change = v;
        int numQ, numN, numD;
        numQ = numN = numD = 0;
        if(change % 25 == 0)
        {
            numQ = change / 25;
        }
        if(numQ > q)
        {
            throw new SimulationException("Quarters");
        }
        change = change - (numQ * 25);
        if(change % 10 == 0)
        {
            numD = change / 10;
        }
        if(numD > d)
        {
            throw new SimulationException("Dimes");
        }
        change = change - (numD * 10);
        if(change % 5 == 0)
        {
            numN = change /5;
        }
        if(numN > n)
        {
            throw new SimulationException("Nickels");
        }
        change = change - (numN * 5);
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
            char[] input = changeReturned.toCharArray();
            for(int i = 0; i < input.length; i++)
            {
                if (input[i] == 'q')
                {
                    q--;
                }
                if (input[i] == 'n')
                {
                    n--;
                }
                if (input[i] == 'd')
                {
                    d--;
                }
                v = 0;

            }
        }
        return changeReturned;
    }

    public void setE(float e) {
        this.e = e;
    }

    public double getE() {
        return e;
    }

    public double getTa() {
        return ta;
    }
}
