the problem:

    Given an input array, find a contiguous subarray with the max possible sum. 

ex:

    array = {-2,1,-3,4,-1,2,1,-5,4}  
    will need to use Kadane's algorithm.

solution:

    Point to the first and last elements of the array. Calculate area between  
    the bars and store it as max_area. Start traversing the list using the  
    the pointer to the lower of the two bars (if they are equal height choose  one randomly). If we encounter a bar of greater height than the original,  
    calculate new area. Repeat until pointers meet. 

complexity:

    time: O(n)  
    space: O(1)  