package com.mycompany.fall2018exception;
public class Main {
    public static void main(String[]args){
      user obj1=new user("123456");
      try{
          obj1.doCheck();
      }catch(runTimeException e){
          e.printStackTrace();
      }
    }
}
