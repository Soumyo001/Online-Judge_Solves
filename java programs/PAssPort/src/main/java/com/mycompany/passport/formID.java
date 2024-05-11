package com.mycompany.passport;
public class formID {
    private String appID;
    public void set(String appID){
        this.appID=appID;
    }
    public String getID(){
        return appID;
    }
    public void showFormInfo(){
        System.out.println("Form ID is "+ getID());
    }
    public void cancelApp(){
        System.out.println("App Cancelled");
    }
}
