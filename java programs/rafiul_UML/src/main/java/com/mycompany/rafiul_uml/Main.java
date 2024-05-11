package com.mycompany.rafiul_uml;
import java.util.Scanner;
public class Main {
    public static void main(String[]args){
        Scanner in=new Scanner(System.in);
        String type;
        type=in.next();
        player player;
        if(type.equals("football")){
            String name,fieldName;int number;
            name=in.next();
            fieldName=in.next();
            number=in.nextInt();
            player=new cricketOrFootball(name,number,fieldName);
            player.getPlayerDetails();
        }
        else if(type.equals("cricket")){
            String name;int number,score;
            name=in.next();
            score=in.nextInt();
            number=in.nextInt();
            player=new cricketPlayer(name,number,score);
            player.getPlayerDetails();
        }
        else if(type.equals("injured")){
            String newType;
            newType=in.next();
            cricketOrFootball obj;
            if(type.equals("cricket")){
                  String name,fieldName;int number;
                  name=in.next();
                  fieldName=in.next();
                  number=in.nextInt();
                  obj=new cricketOrFootball(name,number,fieldName);
                  obj.cricketPlayer();
            }
            else if(type.equals("football")){
                  String name,fieldName;int number;
                  name=in.next();
                  fieldName=in.next();
                  number=in.nextInt();
                 obj=new cricketOrFootball(name,number,fieldName);
                 obj.footballPlayer();
            }
        }
    }
}
