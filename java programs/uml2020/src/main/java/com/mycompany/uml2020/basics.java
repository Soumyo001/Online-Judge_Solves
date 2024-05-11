package com.mycompany.uml2020;
public class basics extends car{
     double thrust;int gear;  
    public basics(double thrust, int gear, String model, int speed) {
        super(model, speed);
        this.thrust = thrust;
        this.gear = gear;
    }
    public void designfor(){
        System.out.println("This design is for basic cars");
    }
    public void rocketEngine(){
        System.out.println("Used for super speed on race cars");
    }
}
