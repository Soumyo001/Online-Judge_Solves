package com.mycompany.passport;
public class Main {
    public static void main(String[]args){
        Online o=new Online();
        Manual m=new Manual();
        o.set("10012220");
        m.set("20023304");
        m.setpassType("Manual");
        o.showFormInfo();
        m.showFormInfo();
        o.cancelApp();
        m.cancelApp();
    }
}
