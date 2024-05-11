package com.mycompany.assignment_uml;
import java.util.Scanner;
public class main {
    public static void main(String[]args){
        Scanner in=new Scanner(System.in);
        String shapeName;
        shapeName=in.nextLine();
        shape obj;
        if(shapeName.equals("circle")){
            double radius;
            String color;boolean value;
            radius=in.nextDouble();
            color=in.next();
            value=in.nextBoolean();
            obj=new circle(radius,color,value);
            System.out.println(obj.getarea());
        }
        else if(shapeName.equals("rectangle")){
            String color;boolean value;
            double width,height;
            color=in.next();
            value=in.nextBoolean();
            width=in.nextDouble();
            height=in.nextDouble();
            obj=new triangle(color,value,width,height);
            System.out.println(obj.getarea());
        }
        else if(shapeName.equals("triangle")){
            String color;boolean value;
            double width,height;
            color=in.next();
            value=in.nextBoolean();
            width=in.nextDouble();
            height=in.nextDouble();
            triangle obj2=new triangle(color,value,width,height);
            obj2.gettriangle();
        }
        else if(shapeName.equals("square")){
            String color;boolean value;
            double width,height;
            color=in.next();
            value=in.nextBoolean();
            width=in.nextDouble();
            height=in.nextDouble();
            triangle obj2=new triangle(color,value,width,height);
            obj2.getsquare();
        }
    }
}
