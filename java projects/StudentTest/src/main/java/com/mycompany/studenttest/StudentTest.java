package com.mycompany.studenttest;
import java.util.Scanner;
import java.util.ArrayList;
public class StudentTest {
    public static void main(String[] args) {
          Scanner sc=new Scanner(System.in);
          ArrayList<Student> s1=new ArrayList<>();
          Student[]s2=new Student[5];
          int max=0;
          String a = null;
          for(int i=0;i<5;i++){
              String name = null,admittedYear = null;
              int id = 0,ageAtAdmission = 0;
              id=sc.nextInt();
              name=sc.next();
              admittedYear=sc.next();
              ageAtAdmission=sc.nextInt();
              s2[i]=new Student(id,name,admittedYear,ageAtAdmission);
              s1.add(s2[i]);
          }
          for(Student s:s1){
              if(s.currentAgeCalculator("2022")>max) {
                  max=s.currentAgeCalculator("2022");
                  a=s.name;
                }
            }
          for(Student s:s1){
              if(s.name.equals(a)){
                  System.out.println("Youngest Student: "+s.name);
                  System.out.println("Current Age: "+ s.currentAgeCalculator("2022"));
                  break;
              }
          }
    }
 }
