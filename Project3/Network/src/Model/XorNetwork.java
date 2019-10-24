package Model;

import Framework.Model;
import Framework.NetworkModel;
import Framework.Pipe;
import Framework.Port;

import java.util.ArrayList;
import java.util.Collection;

public class XorNetwork extends NetworkModel {

    private Port inputPort1;
    private Port inputPort2;
    private Port outputPort;
    ArrayList<Model> modelList = new ArrayList<>();
    ArrayList<Pipe> pipes = new ArrayList<>();

    public XorNetwork(Port p)
    {
        this.outputPort = p;
    }

    @Override
    public void lambda()
    {
        System.out.println(outputPort.getData());

        for(Model m : modelList)
        {
            m.lambda();
        }
    }

    @Override
    public void delta()
    {
        for(Model m : modelList)
        {
            m.delta();
        }
        for(Pipe p : pipes)
        {
            p.Delta();
        }
    }

    public void silentDelta()
    {
        for(int i = 0; i < 4; i++)
        {
            for(Model m : modelList)
            {
                m.delta();
            }
            for(Pipe p : pipes)
            {
                p.Delta();
            }
        }
    }

    @Override
    public void outputPort(Port p)
    {
        this.outputPort = p;
    }

    @Override
    public Port getOutputPort()
    {
        return outputPort;
    }

    @Override
    public Collection<Port> getInputPorts()
    {
        return null;
    }

    public void addModel(Model m)
    {
        modelList.add(m);
    }

    public void addPipe(Pipe p)
    {
        pipes.add(p);
    }

    public void addInputPort1(Port p)
    {
        this.inputPort1 = p;
    }

    public void addInputPort2(Port p)
    {
        this.inputPort2 = p;
    }

    public Port getInputPort1() {
        return inputPort1;
    }

    public Port getInputPort2() {
        return inputPort2;
    }

}
