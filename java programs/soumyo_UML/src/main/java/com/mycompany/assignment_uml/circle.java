package com.mycompany.assignment_uml;
import java.lang.Math;
public class circle extends shape{
    private double radius;
    public circle(double radius,String color,boolean value){
        super(color,value);
        this.radius=radius;
    }
    public double getRadius() {
        return radius;
    }
    public void setRadius(double radius) {
        this.radius = radius;
    }
    public double getarea(){
        return Math.PI*Math.pow(radius,2);
    }
}
