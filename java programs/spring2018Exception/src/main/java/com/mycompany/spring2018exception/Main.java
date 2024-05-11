package com.mycompany.spring2018exception;
public class Main {
    public static void main(String[]args){
        patient p1=new patient("Rafiul","Uttara","A+",50,100,100);
        try{
            p1.doCheck();
        }catch(runTimeException e){
            e.printStackTrace();
        }
    }
}
