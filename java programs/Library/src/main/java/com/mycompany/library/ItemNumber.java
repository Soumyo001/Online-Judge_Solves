package com.mycompany.library;
public class ItemNumber {
    private int ItemNum,fileSize;
    private static int maxFileSize=0;
    public static int getMaxFileSize() {
        return maxFileSize;
    }
    public void seti(int ItemNum){
        this.ItemNum=ItemNum;
    }
    public int getItem(){
        return ItemNum;
    }
    public void seti(int s,int i){
        fileSize=s;
        ItemNum=i;
        if(ItemNumber.maxFileSize<s) maxFileSize=s;
    }
    public int getSize(){
        return fileSize;
    }
}
