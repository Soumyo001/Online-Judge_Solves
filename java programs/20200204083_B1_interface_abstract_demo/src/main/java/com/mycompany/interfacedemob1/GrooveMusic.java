package com.mycompany.interfacedemob1;
public class GrooveMusic extends MusicPlayer{
    public GrooveMusic(String f,String l){
        super(f,l);
    }
    public void musicStatus(String type){
        if(type.equals("play")||type.equals("Play")){
            System.out.println("Playing the file: "+ getF());
        }
        else if(type.equals("add")||type.equals("Add")){
            System.out.println("Adding file: "+getF()+" to the List: "+getL());
        }
    }
}
