package com.mycompany.quiz_1_2nd_question;
import java.util.Scanner;
public class Demo {
    public static void main(String[]args){
        Scanner in=new Scanner(System.in);
        String id,name,w;double balance,amnt;
        id=in.nextLine();
        name=in.nextLine();
        balance=in.nextDouble();
        Account rahimAccount=new Account(id,name,balance);
        w=in.next();
        amnt=in.nextDouble();
        System.out.println(rahimAccount.accountBalance(w,amnt));
        in.close();
    }
}
