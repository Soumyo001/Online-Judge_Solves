package com.mycompany.labfinal;
public class Translator {
    public Translator(){}
    public void decodeSignal(int num){
        if(num==2) System.out.println("Minerals Found!");
        else if(num==3) System.out.println("Microorganism Found!");
        else System.out.println("Water Found!");
    }
}
