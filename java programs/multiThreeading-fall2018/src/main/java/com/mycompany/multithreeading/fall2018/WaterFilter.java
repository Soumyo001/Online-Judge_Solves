package com.mycompany.multithreeading.fall2018;
public class WaterFilter {
            private double currentCapacity;
        
        public WaterFilter() {
                super();
                this.currentCapacity = 0;
        }

        public WaterFilter(double currentCapacity) {
                super();
                this.currentCapacity = currentCapacity;
        }
        
        public void incrementCapacity(double capacity) {
                this.currentCapacity += capacity;
        }
        
        public void decrementCapacity(double capacity) {
                this.currentCapacity -= capacity;
        }
        
        public double getCapacity() {
                return this.currentCapacity;
        }
}
