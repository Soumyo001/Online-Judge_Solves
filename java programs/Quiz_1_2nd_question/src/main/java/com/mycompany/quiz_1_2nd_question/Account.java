package com.mycompany.quiz_1_2nd_question;
public class Account {
    String id,name;double balance;
    public Account(String id,String name,double balance){
        this.id=id;this.name=name;this.balance=balance;
    }
    public double accountBalance(String t,double amnt){
        if(t.compareTo("deposit")==0) return balance+=amnt;
        else{
            if(amnt<balance) return balance-=amnt;
            else return -1;
        }
    }
}