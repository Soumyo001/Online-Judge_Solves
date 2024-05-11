package com.mycompany.passport;
public class Manual extends formID{
    private String passType;
    public void setpassType(String passType){
        this.passType=passType;
    }
    public String getpassType(){
        return passType;
    }
    public void showFormInfo(){
        super.showFormInfo();
        //System.out.println("Form ID is "+ getID());
        System.out.println("App type is "+getpassType());
    }
}
