package Framework;

import java.util.Collection;

/**
 * Abstract class for networks to extend from.
 */
public abstract class NetworkModel implements Model
{
    public NetworkModel(){}

    Collection<Model> models;

    public void addModel(Model m)
    {
        models.add(m);
    }
}