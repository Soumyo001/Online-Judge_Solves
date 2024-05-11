
package com.mycompany.boxdemo;

public class Box {
     double length,heigth,width;
     public Box(double length,double width,double height){
         this.length=length;
         this.heigth=height;
         this.width=width;
     }
     public double volume(double length,double width,double height){
         return height*width*length;
     }
}
