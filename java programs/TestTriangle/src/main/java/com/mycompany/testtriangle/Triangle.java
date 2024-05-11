
package com.mycompany.testtriangle;
public class Triangle {
    private String name;
    private double area;
    public Triangle(){
        
    }
    public Triangle(String name,double area){
        this.name=name;
        this.area=area;
    }
    void set(String name,double area){
        this.name=name;
        this.area=area;
    }
    String getString(){
        return name;
    }
    double getArea(){
        return area;
    }
}
