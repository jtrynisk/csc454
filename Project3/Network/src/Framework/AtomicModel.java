package Framework;

import java.util.Collection;

/**
 * Implements model, the atomic model, for any model to be added to the model
 */
public abstract class AtomicModel implements Model
{
    Collection<Port> ports;

    /**
     * Allows for each model to have its own constructor.
     */
    public AtomicModel(){}

    /**
     * Adds an input port to the model.
     * @param p the port to be added an the input port
     */
    public void addInputPort(Port p)
    {
        ports.add(p);
    }

}
