#include <iostream>
#include "two_sum.h"

// simple swap
void swap(int* array, int i, int j){
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

// standard quicksort implementation
void quicksort(int* array, int start, int end){

    if(start == end){
        return;
    }

    // indexing variables
    int pivot = array[start];
    int i = start;
    int j = start + 1;

    // generating sub-arrays
    while ( j <= end){
        if(array[j] < pivot){
            i++;
            swap(array, i, j);
            j++;
        }
        else{
            j++;
        }
    }

    // inserting pivot to correct position
    swap(array, pivot, i);

    //recursive call
    quicksort(array, start, i);
    quicksort(array, i+1, end);
}

// expects a pointer to an array, the size of the array and a target
// returns a tuple containing two elements from array that sum to target
// will return 00 if no such pair exists
std::tuple<int,int> two_sum(int* array, int start, int end, int target){
    
    //first step is to sort array
    quicksort(array, start, end);

    // can first use an nlogn sort on the array
    // then point to first and last elements
        // if the sum is less than target, increment lower bound
        // if the sume is greater than target, increment upper bound
    int i = start;
    int j = end;
    while(j > i){
        if ((array[i] + array[j]) > target){
            // printf("%d + %d = %d > %d...decrementing j\n",
            // array[i], array[j], array[i] + array[j],target);
            j--;
        }
        else if ((array[i] + array[j]) < target){
            // printf("%d + %d = %d > %d...decrementing j\n",
            // array[i], array[j], array[i] + array[j],target);
            i++;
        }
        else{
            return std::tuple<int,int>(array[i],array[j]);
        }
    }
    return std::tuple<int,int>(0,0);
}
