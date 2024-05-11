package com.mycompany.interfacedemo;
public class defaultMessengerApp extends messenger{
    public defaultMessengerApp(String x, String y) {
        super(x, y);
    }
    public void messegeDetails(String type){
        if(type.equals("receive")||type.equals("Receive")){
            System.out.println("Sending to "+getX()+"the messege "+getY());
        }
        else if(type.equals("sending")||type.equals("Sending")){
            System.out.println(getX()+"sent you the messege: "+ getY());
        }
    }
}
