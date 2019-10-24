package Model;

import Framework.AtomicModel;
import Framework.Model;
import Framework.Pipe;
import Framework.Port;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;

/**
 * Xor model to be implemented in network, extends from atomic model.
 */
public class XOR extends AtomicModel
{
    Port<Integer> inputPort1;
    Port<Integer> inputPort2;
    ArrayList<Port> inputPorts;
    Port outputPort;

    public XOR(Port outputPort)
    {
        this.outputPort = outputPort;
    }

    /**
     * Adds the first input port
     * @param p input port
     */
    public void addInput1(Port p)
    {
        this.inputPort1 = p;
    }

    /**
     * Adds second input port
     * @param p input port
     */
    public void addInput2(Port p)
    {
        this.inputPort2 = p;
    }

    /**
     * Returns input port 1
     * @return input port 1
     */
    public Port<Integer> getInputPort1() {
        return inputPort1;
    }

    /**
     * Returns input port 2
     * @return input port 2
     */
    public Port<Integer> getInputPort2() {
        return inputPort2;
    }

    /**
     * While in verbose prints output ports data.
     */
    @Override
    public void lambda()
    {
        System.out.println("XOR OUTPUT " + outputPort.getData());
    }

    /**
     * XOR's data in the input models.
     */
    @Override
    public void delta()
    {
        outputPort.setData(xor(inputPort1.getData(), inputPort2.getData()));
    }

    /**
     * Adds an output port
     * @param p output port
     */
    @Override
    public void outputPort(Port p)
    {
        this.outputPort = p;
    }

    /**
     * Returns the output port
     * @return output port.
     */
    @Override
    public Port getOutputPort()
    {
        return outputPort;
    }

    /**
     * Returns all the input ports.
     * @return
     */
    @Override
    public ArrayList<Port> getInputPorts()
    {
        return inputPorts;
    }

    /**
     * helper method to xor data.
     * @param i integer 0,1
     * @param j integer 0,1
     * @return returns 0,1 based on the xor
     */
    private int xor(int i, int j)
    {
        if(i != j)
        {
            return 1;
        }
        return 0;
    }
}
