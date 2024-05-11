package com.mycompany.mahin_uml;
public class passedStudents extends students{
    private int number;
    public passedStudents(String name,int id,int number){
        super(name,id);
        this.number=number;
    }
    public int getNumber() {
        return number;
    }
    public void setNumber(int number) {
        this.number = number;
    }
    public void getDetails(){
        System.out.println(getName());
        System.out.println(getId());
        System.out.println(number);
    }
}
