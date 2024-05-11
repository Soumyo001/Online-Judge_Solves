package com.mycompany.dynamicdispatchdemo;
public class Shape {
       private double radius;
        Shape(){}
        Shape(double Radius){
        this.radius=radius;
        }

    public double getRadius() {
        return radius;
    }

    public void setRadius(double radius) {
        this.radius = radius;
    }
   public double calculateArea(){
        return 0.0;
    }
}
