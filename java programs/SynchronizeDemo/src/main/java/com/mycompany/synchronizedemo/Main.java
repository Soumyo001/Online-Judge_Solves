package com.mycompany.synchronizedemo;
public class Main {
	public static void main(String[] args) {
		
		Printer pr = new Printer();
		
		Thread t[] = new Thread[5];
		//try {
		for(int i=0;i<5;i++) {
			Computer com = new Computer(pr, "Computer: "+i);
			t[i] = new Thread(com);
                        t[i].setName("t"+i);
			t[i].start();
                        try{
			     //t[i].join();
		             t[i].sleep(1000);
                        }catch(Exception e){
                            e.printStackTrace();
                        }
		}
		/*}catch(InterruptedException e) {
			e.printStackTrace();
		}*/
		for(int i=0;i<5;i++) {
			System.out.println(t[i].isAlive());
                        System.out.println(Thread.currentThread().getName());
		}
	}

}
