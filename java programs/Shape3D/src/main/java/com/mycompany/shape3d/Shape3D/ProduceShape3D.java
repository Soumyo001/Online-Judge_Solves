package com.mycompany.shape3d.Shape3D;
import java.lang.Math;
public class ProduceShape3D {
    public Shape3D createShape3D(double side){
        Shape3D ob=new Shape3D();
        ob.set("Cube",Math.pow(side,3));
        return ob;
    }
    public Shape3D createShape3D(double radius,double height){
        Shape3D ob=new Shape3D();
        ob.set("Cylinder",Math.PI*Math.pow(radius,2)*height);
        return ob;
    }
    public Shape3D createShape3D(double x,double y,double z){
        Shape3D ob=new Shape3D();
        ob.set("Cuboid",2*(x*y+x*z+y*z));
        return ob;
    }
}
