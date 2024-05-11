package com.mycompany.batsmanselection;
import java.util.Scanner;
public class BatsmanSelection {
    public static void main(String[]args){
        Scanner in=new Scanner(System.in);
        int a,b;
        a=in.nextInt();
        b=in.nextInt();
        Batsman bat=new Batsman(a,b);
        Committee comi=new Committee(bat);
        comi.calculateAverage();
        in.close();
        
    }
}
