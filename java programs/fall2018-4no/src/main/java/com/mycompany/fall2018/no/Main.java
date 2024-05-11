package com.mycompany.fall2018.no;
import java.util.Scanner;
public class Main {
    public static void main(String[]args){
        String n,d,dept;
        int id;
        teacher[]t=new teacher[3];
        student[]s=new student[3];
        Scanner sc=new Scanner(System.in);
        for(int i=0;i<3;i++){
            n=sc.next();
            d=sc.next();
            dept=sc.next();
            t[i]=new teacher(n,d,dept);
        }
        for(int i=0;i<3;i++){
            n=sc.next();
            dept=sc.next();
            id=sc.nextInt();
            s[i]=new student(n,dept,id);
        }
        Searching search=new Searching(t,s);
        search.doSearch(s,"MDSadman");
        search.doSearch(t, "MDBelal");
    }
}
