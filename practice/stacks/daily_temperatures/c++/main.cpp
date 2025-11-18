#include "solution.h"
#include <cstdio>

int main(int argc, char const *argv[])
{
    
    Solution mysol;

    std::vector<int> temperatures = {22, 21, 20};

    printf("[");
    for(const auto& t : mysol.dailyTemperatures(temperatures)){
        printf("%i, ", t);
    }
    printf("]\n");

    return 0;
}
