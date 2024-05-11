package com.mycompany.spring2020.multithreading;
public class Main {
    public static void main(String[]args){
        eqnF f=new eqnF(2);
        eqnG g=new eqnG(3,f);
        FunctionF f1=new FunctionF(f);
        FunctionG g1=new FunctionG(g);
        Thread t1=new Thread(f1);
        Thread t2=new Thread(g1);
        t1.start();
        t2.start();
        try{
            t1.join();
            t2.join();
        }catch(InterruptedException e){
            e.printStackTrace();
        }
        System.out.println(f.value);
        System.out.println(g.value);
    }
}
