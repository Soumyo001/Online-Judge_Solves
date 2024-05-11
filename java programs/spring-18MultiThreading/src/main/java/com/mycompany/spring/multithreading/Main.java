package com.mycompany.spring.multithreading;

public class Main {

    public static void main(String[] args) {
        even v = new even();
        odd o = new odd();
        Thread Even = new Thread(v);
        Thread Odd = new Thread(o);
        Even.start();
        Odd.start();
        try{
            Even.join();
            Odd.join();
        }catch(InterruptedException e){
            e.printStackTrace();
        }
    }
}
