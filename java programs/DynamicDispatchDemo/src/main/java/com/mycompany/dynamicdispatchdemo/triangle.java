package com.mycompany.dynamicdispatchdemo;
public class triangle extends Rectangle{
    public triangle(int w,int h,double r){
        super(w,h,r);
    }
    public double calculateArea(){
        return super.getWidth()*super.getHeight()*0.5;
    }
}
