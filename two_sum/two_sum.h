#ifndef TWOSUM_H
#define TWOSUM_H
#include <tuple>
#include <cstddef>

// expects a pointer to an array, the size of the array and a target
// returns a tuple containing two elements from array that sum to target
// will return 00 if no such pair exists
std::tuple<int,int> two_sum(int* array, int start, int end, int target);
void quicksort(int* array, int start, int end);

#endif