package com.mycompany.multithreeading.fall2018;
import java.util.Random;
public class Main extends Thread{
        
        private static WaterFilter waterFilter;
        
        private Employee employee = new Employee("Elena");
        private Employee employee1 = new Employee("Jimmy");
        
        private Peon peon = new Peon("Caroline");
        private Peon peon1 = new Peon("Bonnie");

        public static void main(String[] args) {
                Main.waterFilter = new WaterFilter();
                
                Main peonThread = new Main();
                Main employeeThread = new Main();
                
                peonThread.start();
                employeeThread.start();
        }
        
        public void run() {
        if (waterFilter.getCapacity() < 0) {
                        this.peon.refillFilter(waterFilter);
                        this.peon1.refillFilter(waterFilter);
                        
                        System.out.println("Water Capacity: " + waterFilter.getCapacity());
                }

                else if (Thread.currentThread().getId() == 14) {
                        this.peon.refillFilter(waterFilter);
                        this.peon1.refillFilter(waterFilter);
                        
                        System.out.println("Water Capacity: " + waterFilter.getCapacity());
                }
                
                else if (Thread.currentThread().getId() == 15) {
                        this.employee.drink(waterFilter);
                        this.employee1.drink(waterFilter);
                        
                        System.out.println("Water Capacity: " + waterFilter.getCapacity());
                }
        }
} 
