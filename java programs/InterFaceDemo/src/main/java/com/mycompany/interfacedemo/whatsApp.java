package com.mycompany.interfacedemo;
public class whatsApp extends modernMessenger{
    public whatsApp(){}
    public whatsApp(String x,String y){
        super(x,y);
    }
    public void messegeStatus(String type){
        if(type.equals("seen")) System.out.println(getY()+" is seen");
        else if(type.equals("sent")) System.out.println(getY()+" is sent");
        else if(type.equals("delivered")) System.out.println(getY()+" is delivered");
    }
}
