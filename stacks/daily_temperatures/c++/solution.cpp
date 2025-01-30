#include "solution.h"
#include <cstdio>

std::vector<int> Solution::dailyTemperatures(std::vector<int>& temperatures){
    
    std::vector<int> stack;
    stack.reserve(temperatures.size());

    for (std::size_t i = 0; i < temperatures.size(); i++)
    {
        if(stack.size() == 0 || temperatures[stack.back()] >= temperatures[i]){
            stack.push_back(i);
        }
        else {
            while ( !(stack.empty()) && temperatures[stack.back()] < temperatures[i] ){
                temperatures[stack.back()] = i - stack.back();
                stack.pop_back();
            }
            stack.push_back(i);
        }
    }
    while (!stack.empty())
    {
        temperatures[stack.back()] = 0;
        stack.pop_back();
    }

    return temperatures;

}