package com.mycompany.interfacedemob1;
import java.util.Scanner;
public class Main {
    public static void main(String[]args){
        Scanner in=new Scanner(System.in);
        String fileName,listName,url;
        double speed,time;
        fileName=in.nextLine();
        listName=in.nextLine();
        url=in.nextLine();
        speed=in.nextDouble();
        time=in.nextDouble();
        VLC app1=new VLC(fileName,listName,speed,time,url);
        GrooveMusic app2=new GrooveMusic(fileName,listName);
        app1.musicStatus("Play");
        app1.videoStatus("add");
        app1.recordStatus();
        app1.speedStatus();
        app1.streamStatus();
        app2.musicStatus("Add");
    }
}
