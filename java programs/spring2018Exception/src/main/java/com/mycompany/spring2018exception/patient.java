package com.mycompany.spring2018exception;
public class patient {
    String name,address,bloodGroup;
    int age,systollicBloodPressure,diastollicBloodPressure;
    public patient(String name, String address, String bloodGroup, int age, int systollicBloodPressure, int diastollicBloodPressure) {
        this.name = name;
        this.address = address;
        this.bloodGroup = bloodGroup;
        this.age = age;
        this.systollicBloodPressure = systollicBloodPressure;
        this.diastollicBloodPressure = diastollicBloodPressure;
    }
    public void doCheck(){
        if(age>=5&&(systollicBloodPressure>=40&&systollicBloodPressure<=250)&&(diastollicBloodPressure>=40&&diastollicBloodPressure<=120)&&(bloodGroup.equals("A+")||bloodGroup.equals("A-")||bloodGroup.equals("B+")||bloodGroup.equals("B-")||bloodGroup.equals("AB+")||bloodGroup.equals("AB-")||bloodGroup.equals("O+")||bloodGroup.equals("O-"))){
            System.out.println("Patient verified!");
        }else throw new runTimeException();
    }
}
