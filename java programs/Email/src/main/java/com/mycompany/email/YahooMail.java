package com.mycompany.email;
import userDefinedExceptions.*;
public class YahooMail {
    public YahooMail(){}
    public void Login(String ID){
        if(ID.contains("@yahoo.com")){
            System.out.println("Yahoo Mail ID login successful");
        }
        else throw new runtimeException();
    }
}
