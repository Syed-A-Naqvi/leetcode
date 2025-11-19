# Car Fleet Problem

## Problem Description

There are `n` cars traveling to the same destination on a one-lane highway.

You are given two arrays of integers `position` and `speed`, both of length `n`.

- `position[i]` is the position of the `ith` car (in miles)
- `speed[i]` is the speed of the `ith` car (in miles per hour)

The destination is at position `target` miles.

A car can **not** pass another car ahead of it. It can only catch up to another car and then drive at the same speed as the car ahead of it.

A **car fleet** is a non-empty set of cars driving at the same position and same speed. A single car is also considered a car fleet.

If a car catches up to a car fleet the moment the fleet reaches the destination, then the car is considered to be part of the fleet.

Return the number of different car fleets that will arrive at the destination.

## Solution 1: Lists and Stacks

1. Create a new car class with position and speed fields.
2. Use provided position and speed arrays to create a single array of car objects in **O(n)** time.
3. Sort the car object array in ascending order in **O(nlogn)** time.
4. Create a new **fleet** stack
5. Loop while **cars** array is not empty:

- Use the car closest to the target (end of cars array), to calculate ETA: $\frac{(target - car.position)}{car.speed}$.
- if the fleet stack is empty, pop the car off the cars array and insert into the fleet stack, this will be the leader of the current fleet.
- if there already is a leader (fleet not empty) and the current car's ETA is <= leader's ETA, pop car off cars array and insert into fleet.
- if current car's ETA > leader's ETA, this car will never catch up to the fleet; increment the number of fleets and clear the fleet stack

6. After the loop exits, increment number of fleets by one to account for the last fleet remaining in the stack.
7. return the number of fleets.

### Complexity

- **Time Complexity**: `O(nlogn)` sorting cars array will take at most `O(nlogn)` time.
- **Space Complexity**: `O(n)` the combined arraylist and stack will never take more than `n` space where `n` is the amount of cars/positions/speeds.

## Solution 2: Linear

1. Create a new car class with position and speed fields.
2. Use provided position and speed arrays to create a single array of car objects in **O(n)** time.
3. Sort the car object array in ascending order of position (last car will be closest to target) in **O(nlogn)** time.
4. Iterate over **cars** array in reverse order:

- calculate ETA: $\frac{(target - car.position)}{car.speed}$ for current car.   
  - if no fleets have been counted yet, numFleets++ and current car becomes leader by default.
- if current car's ETA is > leader's ETA, numFleets++ and curr car becomes new leader.

1. return the number of fleets.

### Complexity

- **Time Complexity**: `O(nlogn)` sorting cars array will take at most `O(nlogn)` time.
- **Space Complexity**: `O(n)` cars arraylist will take additional `n` space where `n` is the amount of cars/positions/speeds.