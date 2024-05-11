package com.mycompany.gamerdemo;
import java.util.Scanner;
public class GamerDemo {
 public static void main(String[]args){
     Scanner in=new Scanner(System.in);
     String s;
     double a,b;
     s=in.nextLine();
     a=in.nextDouble();
     b=in.nextDouble();
     Gamer g=new Gamer(s,a,b);
     System.out.println(g.gamerType);
     System.out.println(g.totalScore);
     System.out.println(g.totalMatches);
     System.out.println(g.calculateFinalScore());
     in.close();
 }   
}
