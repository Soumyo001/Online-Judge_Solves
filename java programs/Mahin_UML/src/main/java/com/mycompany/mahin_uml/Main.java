package com.mycompany.mahin_uml;
import java.util.Scanner;
public class Main {
    public static void main(String[]args){
        Scanner in=new Scanner(System.in);
        String condition;
        condition=in.next();
        students student;
        if(condition.equals("pass")){
            String name;int id,number;
            name=in.next();
            id=in.nextInt();
            number=in.nextInt();
            student=new passedStudents(name,id,number);
            student.getDetails();
        }
        else if(condition.equals("drop")){
            String name;int id;
            double semister;
            name=in.next();
            id=in.nextInt();
            semister=in.nextDouble();
            student=new detailsOfDroppedOrFailedStudents(name,id,semister);
            student.getDetails();
        }
        else if(condition.equals("fail")){
            String name;int id;
            double semister;
            name=in.next();
            id=in.nextInt();
            semister=in.nextDouble();
            detailsOfDroppedOrFailedStudents obj2=new detailsOfDroppedOrFailedStudents(name,id,semister);
            obj2.getFailedStudentDetails();
        }
        in.close();
    }
}
