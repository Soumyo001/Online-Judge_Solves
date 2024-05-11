package com.mycompany.library;
public class Main {
    public static void main(String[]args){
        Book b=new Book();
        EBook e=new EBook();
        b.set("X","Y");
        e.set("A","B");
        b.seti(23);
        e.seti(200,12);
        b.ShowItem();
        b.CheckOut();
        e.ShowItem();
        e.CheckOut();
    }
}