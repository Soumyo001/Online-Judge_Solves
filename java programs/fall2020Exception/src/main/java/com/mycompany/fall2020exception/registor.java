package com.mycompany.fall2020exception;
public class registor {
    String name,NID;
    public registor(String name,String NID){
        this.name=name;
        this.NID=NID;
    }
    public void doCheck(){
        int count = 0;
        for (int i = 0, len = NID.length(); i < len; i++) {
              if (Character.isDigit(NID.charAt(i))) {
              count++;
            }
              else break;
        }
        if (name.matches("[a-zA-Z .]+") && name.length() > 2 && count == 17){
             System.out.println("correct input");
       }else throw new runtimeException();
    }
}
