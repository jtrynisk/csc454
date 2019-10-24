package Framework;

/**
 * Class that simply holds data.
 * @param <T> Type of data held in the port.
 */
public class Port<T>
{
    private T data;

    /**
     * Default constructor.
     */
    public Port(){ }

    /**
     * Constructor that takes the data.
     * @param data the data that is put into the port
     */
    public Port(T data)
    {
        this.data = data;
    }

    /**
     * Returns the data in the port.
     * @return the data in the port.
     */
    public T getData()
    {
        return this.data;
    }

    /**
     * Sets the data to be held in the port.
     */
    public void setData(T data)
    {
        this.data = data;
    }
}
