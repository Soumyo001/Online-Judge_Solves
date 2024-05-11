/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.quiz_1;

/**
 *
 * @author HP
 */
public class Player {
    String player;
    double lifePoints;
    public Player(String player,double lifePoints){
        this.player=player;
        this.lifePoints=lifePoints;
    }
    public void point(double points,boolean i){
        if(i) this.lifePoints+=points;
        else this.lifePoints-=points;
        System.out.println("current life: "+" "+lifePoints);
    }
}
