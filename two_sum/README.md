the problem:

    given an array of numbers and a target, find a pair of numbers that sum to the target.

ex:

    array = {1,4,2,3}, target = 6, return (2,4)

solution:

    The array is sorted in ascending order using quicksort in O(nlogn) time.  
    First and last elements are tracked using pointers i and j.  
    Iterate through the array (O(n)) by incrementing i and decrementing j based on the  
    sum of their elements.  
    Return a pair if it sums to the target, return (0,0) if no such pair is found.  

complexity:

    time: O(nlogn)  
    space: O(1)  