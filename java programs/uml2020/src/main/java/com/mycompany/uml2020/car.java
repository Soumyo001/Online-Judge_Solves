package com.mycompany.uml2020;
public abstract class car implements ferrari,BMW{
   String model;
   int speed;
   public void carDesignbmw(){
       System.out.println("Car design for BMW");
   }
    public car(String model, int speed) {
        this.model = model;
        this.speed = speed;
    }
   public void carDesignferrari(){
       System.out.println("Car design for Ferrari");
   }
   abstract void rocketEngine();
}
