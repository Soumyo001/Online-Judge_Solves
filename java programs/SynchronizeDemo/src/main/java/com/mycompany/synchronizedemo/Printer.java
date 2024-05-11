package com.mycompany.synchronizedemo;
public class Printer {
    	synchronized void print(String message, String whichComputer) {
		System.out.println("Printing request from "+whichComputer);
		System.out.println(message);
	}
}
