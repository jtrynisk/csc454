import java.util.Scanner;

public class Main
{
    public static void main(String[] args)
    {
        String input = "";
        Scanner sc = new Scanner(System.in);
        VendingMachine vm = new VendingMachine();

        double alarmTime = 2.0;
        boolean newAlarm = true;
        for(;;)
        {
            System.out.print("Please enter input: ");
            input = sc.next();

            if(input.equals("exit"))
                break;

            String[] inputArr = input.split(",");

            double eventTime = Double.parseDouble(inputArr[0]);
            input = inputArr[1];

            if(newAlarm){
                alarmTime = eventTime + 2;
                newAlarm = false;
            }
            else{
                //Intentionally left blank
            }
            if(eventTime > alarmTime)
            {
                vm.processInput("", 2);
                vm.processInput(input, 0);
                newAlarm = true;
            }
            else
            {
                vm.processInput(input, eventTime);
            }

            alarmTime = eventTime + 2;

        }
    }
}
