the problem:
given an array of numbers and a target, find a pair of numbers in the array that sum to the target.
ex:
    array = {1,4,2,3}, target = 6, return (2,4)
solution:
    First, the array is sorted in ascending order using quicksort in O(nlogn) time.
    Next, first and last elements are tracked using pointers i and j.
    The array is iterated through in O(n) time until a sum is found.
        if array[i] + array[j] < target increment i.
        if array[i] + array[j] > target decrement j.
        if array[i] + array[j] == target return (array[i], array[j]).
        else return (0,0).
