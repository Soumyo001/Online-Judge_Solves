package com.mycompany.fall2020.multithreading;
public class pizzaStore implements Runnable{
    customer c;
    public pizzaStore(customer c){
        this.c=c;
    }
    int value=0;
    public void run(){
            for(int j=0;;j++){
                System.out.println("cooking");
                try{Thread.sleep(1000);}
                catch(InterruptedException e){e.printStackTrace();}
                c.numOfPizza--;
                value++;
                if(value==5){
                    System.out.println("5 pizza done");
                    value=0;
                }
                if(c.numOfPizza<=0) {System.out.println("cooking done");break;}
            }
    }
}
