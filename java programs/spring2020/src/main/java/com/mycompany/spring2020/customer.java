package com.mycompany.spring2020;
public class customer {
    String name,homeAddress,city,number;
    public customer(String name,String homeAddress,String city,String number){
        this.city=city;
        this.homeAddress=homeAddress;
        this.name=name;
        this.number=number;
    }
    public void doCheck(){
        if((city.equals("Dhaka")||city.equals("Chittagong"))&&number.startsWith("01")){
            System.out.println("Registered");
        }
        else throw new runtimeException();
    }
}
