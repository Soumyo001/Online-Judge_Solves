package com.mycompany.interfacedemo;
public abstract class messenger {
    private String x,y;
    public messenger(){}
    public messenger(String x,String y){
        this.x=x;
        this.y=y;
    }
    public String getX() {
        return x;
    }
    public void setX(String x) {
        this.x = x;
    }
    public String getY() {
        return y;
    }
    public void setY(String y) {
        this.y = y;
    }
    abstract void messegeDetails(String type);
}
