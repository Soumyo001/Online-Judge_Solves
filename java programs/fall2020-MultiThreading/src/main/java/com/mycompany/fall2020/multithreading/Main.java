package com.mycompany.fall2020.multithreading;
public class Main {
    public static void main(String[]args){
        customer c=new customer(10);
        pizzaStore p=new pizzaStore(c);
        Thread t=new Thread(p);
        t.start();
        try{
            t.join();
        }catch(InterruptedException e){
            e.printStackTrace();
        }
    }
}
