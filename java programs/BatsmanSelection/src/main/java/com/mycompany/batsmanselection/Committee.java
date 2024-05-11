package com.mycompany.batsmanselection;
import java.lang.Math;
public class Committee {
    public Batsman batobj;
    public Committee(Batsman batobj){
        this.batobj=batobj;
    }
    public void calculateAverage(){
        System.out.println(batobj.getRuns()/batobj.getOuts());
        int count=0,sum=0,a;
        a=batobj.getRuns()/batobj.getOuts();
        for(int i=a;i!=0;i/=10) count++;
        for(int i=a;i!=0;i/=10,count--){
            sum+=Math.pow((i%10), count);
        }
        if(sum==a) System.out.println("Selected");
        else System.out.println("Rejected");
    }
}
