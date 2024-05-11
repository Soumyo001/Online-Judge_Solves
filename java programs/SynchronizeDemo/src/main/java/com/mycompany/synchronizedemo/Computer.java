package com.mycompany.synchronizedemo;
public class Computer implements Runnable{
    	String name;
	Printer printer;
	
	Computer(Printer printer, String name){
		this.printer = printer;
		this.name = name;
	}
	public void run() {
		printer.print("hello there", name);
                System.out.println(Thread.currentThread().getName());
	}
}
