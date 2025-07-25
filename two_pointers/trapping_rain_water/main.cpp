#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include "../../cusutils.hpp"


class Solution {
public:
    int trap(std::vector<int>& height) {
        
        int i = 0;
        while(height[i] < 1){
            i++;
        }

        int totalTrapped = 0;
        while(i < height.size()){
            
            int j = i+1;
            int currTrapped = 0;
            
            while( j < height.size() && height[j] < height[i] ){
                currTrapped += height[i] - height[j];
                j++;
            }
            
            i = j;
            
            if( j < height.size()){
                totalTrapped += currTrapped;
            }
        
        }

        return totalTrapped;
    }
};


int main(int argc, char const *argv[])
{

    std::vector<int> heights{0,2,0,3,1,0,1,3,2,1};
    
    Solution mysol;

    printf("Total Trapped Rain Water = %d\n", mysol.trap(heights));

    return 0;
}
