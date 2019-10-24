package Model;

import Framework.AtomicModel;
import Framework.Port;

import java.util.ArrayList;
import java.util.Collection;

/**
 * Holds onto data for and feeds into xor2, receives from xor2
 */
public class Memory extends AtomicModel
{
    private ArrayList<Port> inputPorts;
    private Port<Integer> inputPort;
    private Port<Integer> outputPort;

    public Memory(Port outputPort)
    {
        this.outputPort = outputPort;
    }

    /**
     * While in verbose mode prints whats in output port.
     */
    @Override
    public void lambda() {
        System.out.println("MEMORY OUTPUT " + outputPort.getData());
    }

    /**
     * moves data form input to output as per model.
     */
    @Override
    public void delta()
    {
        outputPort.setData(inputPort.getData());
    }

    /**
     * Sets output port
     * @param p port to be the output port
     */
    @Override
    public void outputPort(Port p)
    {
        this.outputPort = p;
    }

    /**
     * Returns the output port
     * @return port
     */
    @Override
    public Port getOutputPort() {
        return outputPort;
    }

    /**
     * Returns all input ports not used in this model.
     * @return the collection of input ports.
     */
    @Override
    public Collection<Port> getInputPorts() {
        return inputPorts;
    }

    /**
     * Returns the input port
     * @return input port.
     */
    public Port<Integer> getInputPort() {
        return inputPort;
    }

    /**
     * Adds input port
     * @param p the port to be added an the input port
     */
    public void addInputPort(Port p)
    {
        this.inputPort = p;
    }

}
