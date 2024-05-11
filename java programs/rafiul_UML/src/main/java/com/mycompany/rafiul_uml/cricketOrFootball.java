package com.mycompany.rafiul_uml;
public class cricketOrFootball extends footballPlayer implements injuredPlayer{
    public cricketOrFootball(String name,int number,String fieldName){
        super(name,number,fieldName);
    }
    public void getPlayerDetails(){
        System.out.println(getName()+"\n"+getNumber()+"\n"+getFieldName());
    }
    public void cricketPlayer(){
         System.out.println(getName()+"\n"+getNumber());
    }
    public void footballPlayer(){
         System.out.println(getName()+"\n"+getNumber()+"\n"+getFieldName());
    }
}
