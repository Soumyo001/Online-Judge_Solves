package com.mycompany.batsmanselection;
public class Batsman {
    private int totalRuns,totalOuts;
    public Batsman(int totalRuns,int totalOuts){
        this.totalRuns=totalRuns;
        this.totalOuts=totalOuts;
    }
    public void set(int totalRuns,int totalOuts){
        this.totalRuns=totalRuns;
        this.totalOuts=totalOuts;
    }
    public int getRuns(){
        return totalRuns;
    }
    public int getOuts(){
        return totalOuts;
    }
}
