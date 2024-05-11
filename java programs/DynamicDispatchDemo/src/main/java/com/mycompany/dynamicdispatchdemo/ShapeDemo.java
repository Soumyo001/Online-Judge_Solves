package com.mycompany.dynamicdispatchdemo;
import java.util.Scanner;
public class ShapeDemo {
    public static void main(String[]args){
        Scanner sc=new Scanner(System.in);
        String s=sc.next();
        /*Shape ob1=new Circle(5.6,true,"Red");
        ob1.setRadius(5.6);
        Circle ob2=new Circle(5.6,true,"Red");
        ob2.setColor("Red");ob2.setValue(true);ob2.setRadius(5);
        System.out.println(ob1.calculateArea());
        System.out.println(ob2.calculateArea());*/
       if(s.equals("circle")){
           Shape obj=new Circle(5.6,true,"red");
           obj.setRadius(5.6);
           System.out.println(obj.calculateArea());
       }
       else if(s.equals("rectangle")){
           Shape obj=new Rectangle(5,6,7);
           System.out.println(obj.calculateArea());
       }
       else if(s.equals("triangle")){
           Shape obj=new triangle(4,5,7);
           System.out.println(obj.calculateArea());
       }
    }
}
