package com.mycompany.shape3d.Shape3D;
public class Shape3D {
    private String shapeName;
    private double shapeArea;
    public Shape3D(String shapeName,double shapeArea){
        this.shapeName=shapeName;this.shapeArea=shapeArea;
    }
    public Shape3D(){}
    public void set(String shapeName,double shapeArea){
        this.shapeName=shapeName;this.shapeArea=shapeArea;
    }
    public double getArea(){
        return shapeArea;
    }
    public String getName(){
        return shapeName;
    }
}
