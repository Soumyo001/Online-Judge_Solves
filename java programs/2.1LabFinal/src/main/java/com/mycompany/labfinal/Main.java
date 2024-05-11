package com.mycompany.labfinal;
import java.util.Scanner;
public class Main {
    public static void main(String[]args){
        Scanner in=new Scanner(System.in);
        int n;
        n=in.nextInt();
        Transceiver obj=new Transceiver();
        obj.setCode(n);
        obj.inspectSignal();
        try{
        if(obj.isValue()){
            Translator obj1=new Translator();
            obj1.decodeSignal(obj.getNum());
        }else throw new myExceptions.invalidInformationException("Invalid Signal Received! Please discard it.");
        }catch(myExceptions.invalidInformationException e){
            e.printStackTrace();
        }
    }
}
