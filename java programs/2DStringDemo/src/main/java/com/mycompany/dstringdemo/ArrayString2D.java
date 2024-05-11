package com.mycompany.dstringdemo;
public class ArrayString2D {
    private int [][]ages;
    private String [][]names;
    msg m;
    String msg;
    String smsg;
    public ArrayString2D(int [][]ages,String[][]names,String msg,msg m){
        this.ages=ages;
        this.names=names;
        this.msg = msg;
        this.m = m;
    }
    public void msg(){
       m.smsg=msg;
    }
    public void showmsg(){
        System.out.println(smsg);
    }
    public int[][] getAges() {
        return ages;
    }
    public void setAges(int[][] ages) {
        this.ages = ages;
    }
    public String[][] getNames() {
        return names;
    }
    public void setNames(String[][] names) {
        this.names = names;
    }
    public int count;
    public int sumArr(int [][] a){
       for(int i=0;i<a.length;i++){
           for(int j=0;j<a[i].length;j++){
               count+=a[i][j];
           }
       }
        return count;
    }
    public int[][] getArr(){
        int arr[][]={{1,2,3},{4,5,6},{7,8,9}};
        return arr;
    }
    public void print(){
        for(int i=0;i<names.length;i++){
            for(int j=0;j<names[i].length;j++){
                System.out.print(names[i][j]+" ");
            }
         System.out.println();
        }
    }
}
