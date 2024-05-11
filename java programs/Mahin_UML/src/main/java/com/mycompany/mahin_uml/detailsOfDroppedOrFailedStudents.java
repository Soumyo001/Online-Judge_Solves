package com.mycompany.mahin_uml;
public class detailsOfDroppedOrFailedStudents extends droppedStudents implements failedStudents{
    public detailsOfDroppedOrFailedStudents(String name,int id,double semister){
        super(name,id,semister);
    }
    public void getDetails(){
        System.out.println(getName()+"\n"+getId()+"\n"+getSemister());
    }
    public void getFailedStudentDetails(){
        System.out.println(getName()+"\n"+getId()+"\n"+getSemister());
    }
}
