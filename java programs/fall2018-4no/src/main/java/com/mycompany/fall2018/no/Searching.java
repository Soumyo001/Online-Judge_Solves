package com.mycompany.fall2018.no;
public class Searching {
    teacher t[];
    student s[];
    public Searching(teacher[] t, student[] s) {
        this.t = t;
        this.s = s;
    }
    public void doSearch(teacher t[],String name){
        for(int i=0;i<t.length;i++){
            if(t[i].name.equals(name)){
                System.out.println(t[i].name);
                System.out.println(t[i].designation);
                System.out.println(t[i].department);
                break;
            }
        }
    }
    public void doSearch(student s[],String name){
        for(int i=0;i<s.length;i++){
            if(s[i].name.equals(name)){
                System.out.println(s[i].name);
                System.out.println(s[i].id);
                System.out.println(s[i].department);
                break;
            }
        }
    }
}
