package com.mycompany.mahin_uml;
public abstract class droppedStudents extends students{
    private double semister;
    public droppedStudents(String name,int id,double semister){
        super(name,id);
        this.semister=semister;
    }
    public double getSemister() {
        return semister;
    }
    public void setSemister(double semister) {
        this.semister = semister;
    }
    public abstract void getDetails();
}
