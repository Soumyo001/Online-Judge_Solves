package com.mycompany.testquadrilateral;
public class Quadrilateral {
    private String type;
    private double quadArea;
    public void set(String type){
        this.type=type;
    }
    public void set1(double quadArea){
        this.quadArea=quadArea;
    }
    public String getType(){
        return type;
    }
    public double getQuadArea(){
        return quadArea;
    }
}
