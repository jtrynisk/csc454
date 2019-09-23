public class VendingMachine
{
    private int quarters, nickels, dimes, total;
    private double totalInserted;
    private boolean changeButton;

    public VendingMachine(int q, int n, int d, boolean changeButton)
    {
        this.quarters = q;
        this.nickels = n;
        this.dimes = d;
        this.changeButton = changeButton;
    }



    public void processInput(int q, int n, int d, boolean buttonPressed)
    {
        quarters += q;
        nickels += n;
        dimes += d;
        changeButton = buttonPressed;
        double totalInserted = (q * .25) + (n * .05) + (d * .1);

        lambda();
        delta();

    }

    private void lambda()
    {
        if(totalInserted >= 1.00)
        {
            while(totalInserted > 1.00)
            {
                System.out.println("coffee");
                totalInserted -= 1.00;
            }
        }

    }

    private void delta()
    {

    }


    public int getQuarters() {
        return quarters;
    }

    public void setQuarters(int quarters) {
        this.quarters = quarters;
    }

    public int getNickels() {
        return nickels;
    }

    public void setNickels(int nickels) {
        this.nickels = nickels;
    }

    public int getDimes() {
        return dimes;
    }

    public void setDimes(int dimes) {
        this.dimes = dimes;
    }

    public int getTotal() {
        return total;
    }

    public void setTotal(int total) {
        this.total = total;
    }

    public boolean isChangeButton() {
        return changeButton;
    }

    public void setChangeButton(boolean changeButton) {
        this.changeButton = changeButton;
    }
}
