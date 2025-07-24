#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include "../../cusutils.hpp"


class Solution {
public:
    int maxArea(std::vector<int>& heights) {
        
        int i = 0;
        int j = heights.size()-1;
        int currMax = 0;

        while(i < j) {
            int area = std::min(heights[i], heights[j]) * (j - i);
            area > currMax ? currMax = area : currMax = currMax;
            heights[i] > heights[j] ? j-- : i++;
        }

        return currMax;

    }
};

int main(int argc, char const *argv[])
{
    std::vector<int> heights = {1,7,2,5,4,7,3,6};
    Solution mysol;
    int solution = mysol.maxArea(heights);

    printf("Max area between two bars = %d\n", solution);
    
    return 0;
}
