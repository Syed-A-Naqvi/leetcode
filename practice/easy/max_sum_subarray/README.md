the problem:

    Given an input array, find a contiguous subarray with the max possible sum. 

ex:

    array = {-2,1,-3,4,-1,2,1,-5,4}  
    will need to use Kadane's algorithm.

solution:

    Start and end pointers will be used to track a potential max sum subarray. Use an iterator  variable j to go through array. if jth element is larger than sum of previous elements, set  
    running sum to jth element and move start and end to j. if jth element + running sum is greater  
    than jth element, add jth element to running sum, mark j as new end for potential subarray and  
    increment j. Continue until j reaches end of array.  
    Start and end will now track a max sum subarray.

complexity:

    this complexity may not be entirely accurate as i create a new vector and implement a printing  
    function which may add to the functionality.

    time: O(n)  
    space: O(1)  