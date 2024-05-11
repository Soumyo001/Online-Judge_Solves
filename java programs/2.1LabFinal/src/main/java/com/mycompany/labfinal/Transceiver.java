package com.mycompany.labfinal;
import myExceptions.*;
public class Transceiver extends ControlCenter{
    private int num,count=0;
    private boolean value=false;
    public Transceiver(){}
    public int getNum() {
        return num;
    }
    public void setNum(int num) {
        this.num = num;
    }
    public void inspectSignal(){
        for(int i=super.getCode();i!=0;i/=10){
            num=i%10;
            if(num==2||num==3) {
                value=true;
                break;
            }
            else{
                for(int j=2;j<num;j++){
                    if(num%j==0) {count++;break;}
                }
                if(count==0&&(num!=1&&num!=0)){
                   value=true;count=0;break;
                }else{
                   count=0;value=false;
                }
            }
        }
    }
    public boolean isValue() {
        return value;
    }
    public void setValue(boolean value) {
        this.value = value;
    }
}
