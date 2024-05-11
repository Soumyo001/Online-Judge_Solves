package com.mycompany.testquadrilateral;
import java.util.Scanner;
public class TestQuadrilateral {
    public static void main(String[]args){
        CreateQuadrilateral ob=new CreateQuadrilateral();
        Scanner in=new Scanner(System.in);
        Quadrilateral o,x,z;
        double a,b,c,d,e,f;
        a=in.nextDouble();
        b=in.nextDouble();
        c=in.nextDouble();
        d=in.nextDouble();
        e=in.nextDouble();
        f=in.nextDouble();
        o=ob.generateQuadrilateral(a);
        System.out.println(o.getType()+" "+o.getQuadArea());
        x=ob.generateQuadrilateral(b,c);
        System.out.println(x.getType()+" "+x.getQuadArea());
        z=ob.generateQuadrilateral(d,e,f);
        System.out.println(z.getType()+" "+z.getQuadArea());
        in.close();
    }
}
