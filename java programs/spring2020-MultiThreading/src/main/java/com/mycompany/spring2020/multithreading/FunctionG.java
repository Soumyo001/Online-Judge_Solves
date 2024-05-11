package com.mycompany.spring2020.multithreading;
public class FunctionG implements Runnable{
    eqnG g;
    public FunctionG(eqnG g) {
        this.g = g;
    }
    public void run(){
        g.eqn();
    }
}
