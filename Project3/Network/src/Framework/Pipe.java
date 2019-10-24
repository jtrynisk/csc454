package Framework;

/**
 * Connects two ports and pushes data from input to ouput.
 */
public class Pipe
{
    Port inputPort, outputPort;

    /**
     * Constructor
     * @param input input port
     * @param output output port
     */
    public Pipe(Port input, Port output)
    {
        this.inputPort = input;
        this.outputPort = output;
    }

    /**
     * Moves data from input port to output port.
     */
    public void Delta()
    {
        outputPort.setData(inputPort.getData());
    }
}
