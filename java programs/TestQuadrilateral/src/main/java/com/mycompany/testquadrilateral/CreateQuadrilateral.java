package com.mycompany.testquadrilateral;
import java.lang.Math;
import java.util.Scanner;
public class CreateQuadrilateral {
    Scanner sc=new Scanner(System.in);
    public Quadrilateral generateQuadrilateral(double side){
        Quadrilateral ob=new Quadrilateral();
        String s=sc.nextLine();
        ob.set(s);
        ob.set1(Math.pow(side,2));
        return ob;
    }
    public Quadrilateral generateQuadrilateral(double side,double base){
        Quadrilateral ob=new Quadrilateral();
        String s=sc.nextLine();
        ob.set(s);
        ob.set1(base*side);
        return ob;
    }
    public Quadrilateral generateQuadrilateral(double side1,double side2,double height){
        Quadrilateral ob=new Quadrilateral();
        String s=sc.nextLine();
        ob.set(s);
        ob.set1(0.5*(side1+side2)*height);
        return ob;
    }
}
