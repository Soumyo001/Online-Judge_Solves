package com.mycompany.testtriangle;

import java.util.Scanner;

public class objOfTriangle {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s,z,x;
        double a, b, c,d,e,f;
        a = sc.nextDouble();
        b = sc.nextDouble();
        c = sc.nextDouble();
        d = sc.nextDouble();
        e = sc.nextDouble();
        f = sc.nextDouble();
        s = sc.nextLine();
        z = sc.nextLine();
        x = sc.nextLine();
        Triangle t;
        GenerateTriangle gt = new GenerateTriangle();
        t = gt.createTriangle(s, a);
        System.out.println(t.getString() + " " + t.getArea());
        t = gt.createTriangle(z, b, c);
        System.out.println(t.getString() + " " + t.getArea());
        t = gt.createTriangle(x, d, e, f);
        System.out.println(t.getString() + " " + t.getArea());
        sc.close();
    }
}
