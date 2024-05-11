package com.mycompany.fall2020exception;
public class Main {
    public static void main(String[]args){
        registor r=new registor("MD Sadman Israk","12135031586743621");
        try{
            r.doCheck();
        }catch(runtimeException e){
            e.printStackTrace();
        }
    }
}
