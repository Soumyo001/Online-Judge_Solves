package com.mycompany.boxdemo;
import java.util.Scanner;
public class BoxDemo {
    public static void main(String[]args){
    Scanner input=new Scanner(System.in);
    double l,w,h;
    l=input.nextDouble();
    h=input.nextDouble();
    w=input.nextDouble();
    Box b=new Box(l,w,h);
    System.out.println(b.volume(l,w,h));
    input.close();
}
}
