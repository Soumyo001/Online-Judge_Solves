package com.mycompany.interfacedemob1;
public abstract class MediaPlayer extends MusicPlayer implements VideoPlayer{
    private double s,d;
    public MediaPlayer(){}
    public MediaPlayer(String f,String l,double s,double d){
        super(f,l);
        this.s=s;
        this.d=d;
    }
    public double getS() {
        return s;
    }
    public void setS(double s) {
        this.s = s;
    }
    public double getD() {
        return d;
    }
    public void setD(double d) {
        this.d = d;
    }
    public void musicStatus(String type){
        if(type.equals("play")||type.equals("Play")){
            System.out.println("Playing the file: "+ getF());
        }
        else if(type.equals("add")||type.equals("Add")){
            System.out.println("Adding file: "+getF()+" to the List: "+getL());
        }
    }
    public void videoStatus(String type){
        if(type.equals("play")||type.equals("Play")){
            System.out.println("Playing the file: "+getF());
        }
        else if(type.equals("add")||type.equals("Add")){
            System.out.println("Adding subtittles file "+getS()+".srt in the File "+getF());
        }
    }
    public void recordStatus(){
        System.out.println("File: "+getF()+" recorded for: "+getD()+" seconds");
    }
    public void speedStatus(){
        System.out.println("Changing speed of File: "+getF()+" to speed "+getS());
    }
}