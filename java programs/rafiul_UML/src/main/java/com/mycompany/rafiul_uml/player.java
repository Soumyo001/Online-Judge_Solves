package com.mycompany.rafiul_uml;
public class player {
    private String name;
    private int number;
    public player(String name,int number){
        this.name=name;
        this.number=number;
    }
    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    public int getNumber() {
        return number;
    }
    public void setNumber(int number) {
        this.number = number;
    }
    public void getPlayerDetails(){
        System.out.println("No player to show");
    }
}
