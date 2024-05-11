package com.mycompany.dynamicdispatchdemo;
public class Rectangle extends Shape{
    private int width,height;
    public Rectangle(int width,int height,double radius){
       super(radius);
       this.width=width;
       this.height=height;
    }
    public double calculateArea(){
        return width*height;
    }
    public int getWidth() {
        return width;
    }
    public void setWidth(int width) {
        this.width = width;
    }
    public int getHeight() {
        return height;
    }
    public void setHeight(int height) {
        this.height = height;
    }
}
