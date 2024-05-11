package com.mycompany.multithreeading.fall2018;
import java.util.Random;
public class Peon {
       private String name;
        
        public Peon() {
                
        }
        
        public Peon(String name) {
                this.name = name;
        }
        
        public void refillFilter(WaterFilter wf) {
                Random random = new Random();
                
                double randomCapacity = random.nextDouble() * (5 - 1) + 1;
                
                wf.incrementCapacity(randomCapacity);
                
                System.out.println("Peon " + this.name + " refilled " + randomCapacity + " litres.");
        }
}
