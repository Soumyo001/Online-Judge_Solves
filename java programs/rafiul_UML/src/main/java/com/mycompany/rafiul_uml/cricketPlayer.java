package com.mycompany.rafiul_uml;
public class cricketPlayer extends player{
    private int score;
    public cricketPlayer(String name,int number,int score){
        super(name,number);
        this.score=score;
    }
    public int getScore() {
        return score;
    }
    public void setScore(int score) {
        this.score = score;
    }
    public void getPlayerDetails(){
        System.out.println(getName()+"\n"+getNumber()+"\n"+score);
    }
}
