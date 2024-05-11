package com.mycompany.string;
import java.util.Scanner;
public class string {
    public static void main(String[]args){
        Scanner sc=new Scanner(System.in);
        String[]names=new String[5];
        for(int i=0;i<5;i++){
            names[i]=sc.nextLine();
        }
        for(int i=0;i<4;i++){
            for(int j=i+1;j<5;j++){
                if((int)names[i].charAt(0)>(int)names[j].charAt(0)){
                    String t;
                    t=names[i];
                    names[i]=names[j];
                    names[i]=t;
                }
            }
        }
        for(int i=0;i<10;i++){
            System.out.println(names[i]);
        }
        sc.close();
    }
}
