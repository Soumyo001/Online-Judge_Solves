package com.mycompany.assignment_uml;
public class triangle extends rectangle implements squareandtriangle{
    public triangle(String color,boolean value,double width,double height){
        super(color,value,width,height);
    }
    public double getarea(){
        return getWidth()*getHeight();
    }
    public void gettriangle(){
        System.out.println(0.5*getWidth()*getHeight());
    }
    public void getsquare(){
        System.out.println(getWidth()*getHeight());
    }
}
