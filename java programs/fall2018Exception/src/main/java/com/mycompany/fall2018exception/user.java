package com.mycompany.fall2018exception;
public class user {
    String pin;
    public user(String pin){
        this.pin=pin;
    }
    public void doCheck(){
        int count=0;
        for(int i=0;i<pin.length();i++){
            if(Character.isDigit(pin.charAt(i))){
                count++;
            }else{
                break;
            }
        }
        if(count==pin.length()) System.out.println("pin matched");
        else throw new runTimeException();
    }
}
