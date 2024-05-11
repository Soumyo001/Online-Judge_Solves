package com.mycompany.spring2020.multithreading;
public class eqnG {
    int j,value;
    eqnF f;
    public eqnG(int j, eqnF f) {
        this.j = j;
        this.f = f;
    }
    public void eqn(){
        value=f.eqn(j)+3*j;
    }
}
