package Main;

import Framework.Pipe;
import Framework.Port;
import Model.XOR;
import Model.Memory;
import Model.XorNetwork;

import java.util.Scanner;

public class Main
{

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String input = "";

        Port xor1Output = new Port(0);
        Port xor2Output = new Port(0);
        Port memOutput = new Port(0);
        XorNetwork network = new XorNetwork(new Port(0));
        network.addInputPort1(new Port(0));
        network.addInputPort2(new Port(0));

        //Setup the three models.
        XOR xor1 = new XOR(xor1Output);
        XOR xor2 = new XOR(xor2Output);
        Memory memory = new Memory(memOutput);
        memory.addInputPort(new Port(0));

        //Add xor inputs
        xor1.addInput1(new Port(0));
        xor1.addInput2(new Port(0));
        xor2.addInput1(new Port(0));
        xor2.addInput2(new Port(0));

        //Setup the pipes.
        Pipe xorToXor = new Pipe(xor1.getOutputPort(), xor2.getInputPort1());
        Pipe xorToMem = new Pipe(xor2.getOutputPort(), memory.getInputPort());
        Pipe memToXor2 = new Pipe(memory.getOutputPort(), xor2.getInputPort2());
        Pipe xor2toOut = new Pipe(xor2.getOutputPort(), network.getOutputPort());
        Pipe networkToXor = new Pipe(network.getInputPort1(), xor1.getInputPort1());
        Pipe networkToXor2 = new Pipe(network.getInputPort2(), xor1.getInputPort2());

        //Place pipes
        network.addPipe(xorToXor);
        network.addPipe(xor2toOut);
        network.addPipe(xorToMem);
        network.addPipe(memToXor2);
        network.addPipe(networkToXor);
        network.addPipe(networkToXor2);

        //Add models
        network.addModel(xor1);
        network.addModel(xor2);
        network.addModel(memory);

        //Figure out which mode
        System.out.println("Verbose or Regular mode?");
        input = sc.next();

        if(input.toLowerCase().equals("v"))
        {
            while(input != "exit")
            {
                System.out.print("Input: ");
                input = sc.next();
                String[] inputArr = input.split(",");
                network.getInputPort1().setData(Integer.parseInt(inputArr[0]));
                network.getInputPort2().setData(Integer.parseInt(inputArr[1]));

                network.lambda();
                network.delta();
            }
        }
        else
        {
            while(input != "exit")
            {
                System.out.print("Input: ");
                input = sc.next();
                String[] inputArr = input.split(",");
                network.getInputPort1().setData(Integer.parseInt(inputArr[0]));
                network.getInputPort2().setData(Integer.parseInt(inputArr[1]));

                network.lambda();
                network.silentDelta();
            }
        }




    }
}
