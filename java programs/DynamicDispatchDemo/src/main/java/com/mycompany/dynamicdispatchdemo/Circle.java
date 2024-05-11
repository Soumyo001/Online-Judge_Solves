package com.mycompany.dynamicdispatchdemo;
//import java.lang.Math;
public class Circle extends Shape{
    private boolean value;
    private String color;
    Circle(){}
    public Circle(double radius,boolean value,String color){
        super(radius);
        this.value=value;
        this.color=color;
    }

    public boolean isValue() {
        return value;
    }

    public void setValue(boolean value) {
        this.value = value;
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }
    public double calculateArea(){
        return Math.PI*Math.pow(getRadius(),2);
    }
}
