package com.mycompany.spring2020;
public class Main {
    public static void main(String[]args){
        customer obj1=new customer("Sadman","siddhesshwari","Dhaka","01915439455");
        try{
            obj1.doCheck();
        }catch(runtimeException e){
            e.printStackTrace();
        }
    }
}
