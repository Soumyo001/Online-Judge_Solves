package com.mycompany.email;
public class Gmail {
    public Gmail(){}
    public void Login(String ID)throws userDefinedExceptions.compileTimeException{
        //try{
        if(ID.contains("@gmail.com")){
            System.out.println("Gmail ID login successful");
        }
        else throw new userDefinedExceptions.compileTimeException();
        /*}catch(userDefinedExceptions.compileTimeException e){
            System.out.println(e);
        }*/
    }
}
