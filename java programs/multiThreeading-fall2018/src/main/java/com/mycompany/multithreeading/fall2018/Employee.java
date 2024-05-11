package com.mycompany.multithreeading.fall2018;

import java.util.Random;

public class Employee {
            private String name;

        public Employee() {
                super();
        }

        public Employee(String name) {
                super();
                this.name = name;
        }
        
        public void drink(WaterFilter wf) {
                Random random = new Random();
                
                double randomCapacity = random.nextDouble() * (5 - 1) + 1;
                
                if (wf.getCapacity() <= 0.5) {
                        System.out.println("Employee " + this.name + " has informed peon to refill water.");
                }
                
                else {
                        wf.decrementCapacity(randomCapacity);
                        System.out.println("Employee " + this.name + " drank " + randomCapacity + " litres.");
                }
        }
}
