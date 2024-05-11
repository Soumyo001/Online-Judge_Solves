package com.mycompany.uml2020;
import java.util.Scanner;
public class Main {
    public static void main(String[]args){
        Scanner sc=new Scanner(System.in);
        String t=sc.nextLine();
        if(t.equals("race car")){
            basics b=new raceCar(3.00,9,"7A05",400);
            b.rocketEngine();
        }
        else if(t.equals("basic car")){
            basics b=new basics(3.00,6,"7A00XE05",200);
            b.designfor();
        }
    }
}
