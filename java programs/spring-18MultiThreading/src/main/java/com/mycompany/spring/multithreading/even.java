package com.mycompany.spring.multithreading;
public class even implements Runnable{
    public void run(){
        for(int i=1;i<=100;i++){
            if(i%2==0) System.out.println("Even Number :"+i);
        }
    }
}
