package com.mycompany.gamerdemo;
public class Gamer {
    public String gamerType;
    public double totalScore,totalMatches;
    public Gamer(){
        totalScore=totalMatches=-0.1;
    }
    public Gamer(String gamerType,double totalScore,double totalMatches){
        this.gamerType=gamerType;
        this.totalMatches=totalMatches;
        this.totalScore=totalScore;
    }
    public double calculateFinalScore(){
        if(gamerType=="noob") return ((2*totalScore*totalMatches)/(totalScore+totalMatches));
        else return totalScore/totalMatches;
    }
}
