package com.mycompany.interfacedemob1;
public class VLC extends MediaPlayer{
    private String u;
    public VLC(){super();}
    public VLC(String f,String l,double s,double d,String u){
        super(f,l,s,d);
        this.u=u;
    }
    public String getU() {
        return u;
    }
    public void setU(String u) {
        this.u = u;
    }
    public void streamStatus(){
        System.out.println("Streaming video from website: "+getU());
    }
}
