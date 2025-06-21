package stacks.car_fleet;

import java.util.ArrayList;

class Main {
    public static void main(String[] args){
        
        int[] positions = {4,1,0,7};
        int[] speed = {2,2,1,1};

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
        ArrayList<Car> cars = new ArrayList<>();
        for (int i = 0; i < speed.length; i++) {
            cars.add(new Car(position[i], speed[i]));
        }
        cars.sort(null);

        int numFleets = 0;
        int leaderETA = 0;
        for (int i = cars.size()-1; i > -1; i--) {
            
            Car car = cars.get(i);
            int currETA = (target - car.position) / car.speed;

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