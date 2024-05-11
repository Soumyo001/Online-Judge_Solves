package com.mycompany.quiz_1;
import java.util.Scanner;
public class Demo {
    public static void main(String[]args){
        Scanner in=new Scanner(System.in);
        String name,position;double cl;boolean value=true;
        name=in.nextLine();position=in.nextLine();cl=in.nextDouble();
        Player p1=new Player(name,cl);
        if(position.compareTo("dead")==0){
            value=false;
            p1.point(200,value);
        }
        else p1.point(500,value);     
        in.close();
    }
}
