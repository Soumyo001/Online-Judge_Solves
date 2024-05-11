package com.mycompany.email;
import userDefinedExceptions.*;
public class Main {
    public static void main(String[]args){
         Gmail id1=new Gmail();
         YahooMail id2=new YahooMail();
         try{
              id1.Login("soumyo@yahoo.com");
         }catch(compileTimeException e){
             System.out.println(e);
         }
         try{
             id2.Login("soumyo@gmail.com");
         }catch(runtimeException e){
             e.printStackTrace();
         }
     }
}
