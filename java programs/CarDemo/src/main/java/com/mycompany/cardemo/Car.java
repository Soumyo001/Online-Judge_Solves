package com.mycompany.cardemo;
public class Car {
    String brand;
    double model,as;
    public Car(){
        as=-1.0;
    }
    public Car(String brand,double model,double as){
        this.brand=brand;
        this.model=model;
        this.as=as;
    }
    public double distance(double time){
        return as*time;
    }
}
