package com.mycompany.multithreading;
public class Main {
    public static void main(String[]args){
        pcThread pt=new pcThread();
        thread tp1=new thread(pt);
        thread tp2=new thread(pt);
        Thread t1=new Thread(tp1);
        Thread t2=new Thread(tp2);
        t1.start();
        t2.start();
        try{
            t1.join();
            t2.join();
        }catch(InterruptedException e){
            e.printStackTrace();
        }
        System.out.println(pt.item);
    }
}
