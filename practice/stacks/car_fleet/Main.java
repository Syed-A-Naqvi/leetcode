package stacks.car_fleet;

import java.util.Arrays;

class Main {
    public static void main(String[] args){
        
        int[] positions = {6,8};
        int[] speed = {3,2};

        Solution mysol = new Solution();

        mysol.carFleet(10, positions, speed);

    }
}

class Solution {

    class Car implements Comparable<Car>{
        
        int position;
        int speed;

        public Car(int pos, int spd){
            this.position = pos;
            this.speed = spd;
        }
        
        @Override
        public int compareTo(Car other){
            return this.position - other.position;
        }

        @Override
        public String toString(){
            return String.format("[%d, %d]", this.position, this.speed);
        }

    }

    public int carFleet(int target, int[] position, int[] speed) {
        
        // sorting cars in order of furthest to closest to target
        Car[] cars = new Car[position.length];
        for (int i = 0; i < speed.length; i++) {
            cars[i] = new Car(position[i], speed[i]);
        }
        Arrays.sort(cars);

        System.out.println(Arrays.toString(cars));

        int numFleets = 0;
        float leaderETA = 0;
        for (int i = cars.length-1; i > -1; i--) {
            
            Car car = cars[i];
            float currETA = (float)(target - car.position) / car.speed;

            if (numFleets == 0) {
                numFleets++;
                leaderETA = currETA;
                continue;
            }

            if(currETA > leaderETA){
                numFleets++;
                leaderETA = currETA;
            }
        }

        System.out.println("Fleets: " + numFleets);
        return numFleets;

    }

}