package Framework;

import java.util.Collection;

/**
 * Interface for models/networks
 * @param <I> I input type
 * @param <O> O output type
 */
public interface Model<I, O>
{
    void lambda();

    void delta();

    void outputPort(Port p);

    Port getOutputPort();

    Collection<Port> getInputPorts();
}
