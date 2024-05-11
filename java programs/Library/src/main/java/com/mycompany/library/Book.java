package com.mycompany.library;
public class Book extends ItemNumber{
    private String BookName,AuthorName;
    public Book(){};
    public Book(String BookName,String AuthorName){
        this.BookName=BookName;
        this.AuthorName=AuthorName;
    }
    public void set(String BookName,String AuthorName){
        this.BookName=BookName;
        this.AuthorName=AuthorName;
    }
    public String getBook(){
        return BookName;
    }
    public String getAuthor(){
        return AuthorName;
    }
    public void CheckOut(){
        System.out.println("Checked Out");
    }
    public void ShowItem(){
        System.out.println("Item Number is "+ getItem());
        System.out.println("Author name "+ getAuthor());
        System.out.println("Book name "+ getBook());
    }
}
