public class SimulationException extends Exception
{
    String message;

    /**
     * Constructor
     * @param message
     *          what the machine was out of.
     */
    SimulationException(String message)
    {
        this.message = message;
    }

}
