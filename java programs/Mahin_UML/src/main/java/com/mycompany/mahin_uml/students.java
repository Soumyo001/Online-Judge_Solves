package com.mycompany.mahin_uml;
public class students{
    private int id;
    private String name;
    public students(String name,int id){
        this.name=name;
        this.id=id;
    }
    public int getId() {
        return id;
    }
    public void setId(int id) {
        this.id = id;
    }
    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    public void getDetails(){
        System.out.println("No Name or id");
    }
}
