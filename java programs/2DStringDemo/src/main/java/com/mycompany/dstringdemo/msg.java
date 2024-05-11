/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.dstringdemo;

/**
 *
 * @author HP
 */
public class msg {
    String msg;
    ArrayString2D a;
    String smsg;
    msg(String msg,ArrayString2D a){
        this.msg=msg;
        this.a = a;
    }
    public void msg(){
        a.smsg=msg;
    }
    public void showmsg(){
        System.out.println(smsg);
    }
}
