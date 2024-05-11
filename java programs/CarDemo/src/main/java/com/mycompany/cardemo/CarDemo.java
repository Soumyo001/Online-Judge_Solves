package com.mycompany.cardemo;
import java.util.Scanner;
public class CarDemo {
   public static void main(String[]args){
       Scanner in=new Scanner(System.in);
       String a;double b,s,x;
       a=in.nextLine();
       b=in.nextDouble();
       s=in.nextDouble();
       x=in.nextDouble();
       Car ob=new Car(a,b,s);
       System.out.println(ob.brand);
       System.out.println(ob.model);
       System.out.println(ob.as);
       System.out.println(ob.distance(x));
       in.close();
   }    
}
