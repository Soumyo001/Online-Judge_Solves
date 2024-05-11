package com.mycompany.assignment_uml;
public abstract class rectangle extends shape{
    private double width,height;
    public rectangle(String color,boolean value,double width,double height){
        super(color,value);
        this.width=width;
        this.height=height;
    }
    public double getWidth() {
        return width;
    }
    public void setWidth(double width) {
        this.width = width;
    }
    public double getHeight() {
        return height;
    }
    public void setHeight(double height) {
        this.height = height;
    }
    public abstract double getarea();
}
