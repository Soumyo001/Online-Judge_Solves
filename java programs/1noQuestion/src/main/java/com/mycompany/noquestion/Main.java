package com.mycompany.noquestion;
import java.util.Scanner;
public class Main {
    public static void main(String[]args){
        double a;
        int b;
        Scanner sc=new Scanner(System.in);
        a=sc.nextDouble();
        b=sc.nextInt();
        try{
            if((a>=3.0&&a<=3.6)&&(b>=8&&b<=16)){
                System.out.println("Correct Input");
             }
            else throw new Exceptions();
        }catch(Exceptions e){
            e.printStackTrace();
        }
    }
}
