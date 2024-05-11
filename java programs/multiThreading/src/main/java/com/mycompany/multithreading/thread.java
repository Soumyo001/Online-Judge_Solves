package com.mycompany.multithreading;
public class thread implements Runnable{
    pcThread pt;
    public thread(pcThread pt){
        this.pt=pt;
    }
    public void run(){
        for(int i=0;i<100000;i++){
            synchronized(pt){
            pt.addItem();
            }
        }
        //System.out.println("after main thread excecution :"+pt.item);
    }
}
