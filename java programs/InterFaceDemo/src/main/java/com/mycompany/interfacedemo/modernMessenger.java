package com.mycompany.interfacedemo;
public abstract class modernMessenger extends messenger implements caller{
    public modernMessenger(){}
    public modernMessenger(String x,String y){
        super(x,y);
    }
    public void callDetails(String type){
        if(type.equals("receive")||type.equals("Receive")){
            System.out.println(getX()+" is calling you");
        }
        else if(type.equals("sending")||type.equals("Sending")){
            System.out.println("Calling "+getX());
        }
    }
    public void messegeDetails(String type){
        if(type.equals("receive")||type.equals("Receive")){
            System.out.println("Sending to "+getX()+" the messege "+getY());
        }
        else if(type.equals("sending")||type.equals("Sending")){
            System.out.println(getX()+" sent you the messege: "+ getY());
        }
    }
    public void photo(String type){
        if(type.equals("receive")||type.equals("Receive")){
            System.out.println(getX()+" sent you the image: "+getY()+".jpg");
        }
        else if(type.equals("sending")||type.equals("Sending")){
            System.out.println("Sending to "+getX()+" the image: "+getY()+".jpg");
        }
    }
}
