package com.mycompany.testtriangle;
import java.lang.Math;
public class GenerateTriangle {
    public GenerateTriangle(){
        
    }
    Triangle createTriangle(String n,double side){
        double area=((Math.sqrt(3))/4)*(Math.pow(side,2));
        Triangle tri=new Triangle();
        tri.set(n,area);
        return tri;
    }
     Triangle createTriangle(String n,double side,double base){
        double area=0.5*base*side;
        Triangle tri=new Triangle();
        tri.set(n,area);
        return tri;
    }
    Triangle createTriangle(String n,double side1,double side2,double side3){
        double s=(side1+side2+side3)/2;
        double area=Math.sqrt(s*(s-side1)*(s-side2)*(s-side3));
        Triangle tri=new Triangle();
        tri.set(n,area);
        return tri;
    }
}
