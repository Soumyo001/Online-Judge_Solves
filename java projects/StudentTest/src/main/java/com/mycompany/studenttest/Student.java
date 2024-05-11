package com.mycompany.studenttest;
public class Student {
    public int id,ageAtAdmissionTime;
    public String name,admittedYear;
    public Student(int id, String name, String admittedYear, int ageAtAdmissionTime) {
        this.id = id;
        this.ageAtAdmissionTime = ageAtAdmissionTime;
        this.name = name;
        this.admittedYear = admittedYear;
    }
    public int currentAgeCalculator(String currentYear){
        return ageAtAdmissionTime+(Integer.parseInt(currentYear)-Integer.parseInt(admittedYear));
    }
}
