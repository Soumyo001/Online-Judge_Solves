package com.mycompany.rafiul_uml;
public abstract class footballPlayer extends player{
    private String fieldName;
    public footballPlayer(String name,int number,String fieldName){
        super(name,number);
        this.fieldName=fieldName;
    }
    public String getFieldName() {
        return fieldName;
    }
    public void setFieldName(String fieldName) {
        this.fieldName = fieldName;
    }
    public abstract void getPlayerDetails();
}
