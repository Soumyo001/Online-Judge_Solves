package com.mycompany.spring2020.multithreading;
public class FunctionF implements Runnable{
    eqnF f;
    public FunctionF(eqnF f){
        this.f=f;
    }
    public void run(){
        f.eqn();
    }
}
