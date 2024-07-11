#include "two_sum.h"
#include <iostream>
#include <cstdio>


int main(int argc, char const *argv[])
{
    int array[] = {3,2,10,11,7,15};
    
    int target = 9;
    std::tuple<int,int> pair = two_sum(array, 0, 5, target);

    printf("First pair that sums to target %d is (%d,%d)\n",
            target, std::get<0>(pair), std::get<1>(pair));

    return 0;
}
