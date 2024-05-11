package com.mycompany.interfacedemob1;
public abstract class MusicPlayer {
    private String f,l;
    public MusicPlayer(){}
    public MusicPlayer(String f,String l){
        this.f=f;
        this.l=l;
    }
    public String getF() {
        return f;
    }
    public void setF(String f) {
        this.f = f;
    }
    public String getL() {
        return l;
    }
    public void setL(String l) {
        this.l = l;
    }
    abstract void musicStatus(String type);
}
