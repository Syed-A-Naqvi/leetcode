the problem:

    given an array of numbers and a target, find a pair of numbers that sum to the target.

ex:

    array = {1,4,2,3}, target = 6, return (2,4)

solution:

    Iterate through the array calculating the required complement of each element so that the pair  
    sum to the target. Search for the complement in a hashmap and if no such complement exists add  
    the original element into the map.  
    Continue iterating through the array checking for the complement of each element in the hashmap.  
    Once a complement is found, output the pair. If iteration reaches the end of the array output (0,0).

complexity:

    Time: O(n)  
    Space: O(n)