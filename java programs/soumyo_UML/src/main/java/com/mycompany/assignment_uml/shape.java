package com.mycompany.assignment_uml;
public class shape {
    private String color;
    private boolean value;
    public shape(String color,boolean value){
        this.color=color;
        this.value=value;
    }
    public String getColor() {
        return color;
    }
    public void setColor(String color) {
        this.color = color;
    }
    public boolean isValue() {
        return value;
    }
    public void setValue(boolean value) {
        this.value = value;
    }
    public double getarea(){
        return 0.0;
    }
}
