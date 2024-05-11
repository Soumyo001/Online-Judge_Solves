package com.mycompany.interfacedemo;
import java.util.Scanner;
public class main {
    public static void main(String[]args){
        Scanner sc=new Scanner(System.in);
        String a,b;
        a=sc.nextLine();
        b=sc.nextLine();
        whatsApp app1=new whatsApp(a,b);
        defaultMessengerApp app2=new defaultMessengerApp(a,b);
        app1.messegeDetails("sending");
        app1.callDetails("Receive");
        app1.messegeStatus("sent");
        app2.messegeDetails("receive");
    }
}
