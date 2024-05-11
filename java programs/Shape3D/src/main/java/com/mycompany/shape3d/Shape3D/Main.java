package com.mycompany.shape3d.Shape3D;

public class Main {

    public static void main(String[] args) {
        Shape3D ob2;
        ProduceShape3D ob1 = new ProduceShape3D();
        System.out.println((ob2 = ob1.createShape3D(3)).getName() + "\n" + (ob2 = ob1.createShape3D(3)).getArea());
        System.out.println((ob2 = ob1.createShape3D(3, 4)).getName() + "\n" + (ob2 = ob1.createShape3D(3, 4)).getArea());
        System.out.println((ob2 = ob1.createShape3D(3, 4, 5)).getName() + "\n" + (ob2 = ob1.createShape3D(3, 4, 5)).getArea());
    }
}
