#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include "../../cusutils.hpp"

class Solution
{
    public:
        std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
            
            // sorting the vector in non-decreasing order for easier processing O(nlogn)
            std::sort(nums.begin(), nums.end());

            std::vector<std::vector<int>> solutions;

            std::cout << vec_to_string(nums) << std::endl;
            
            // for each element we run an O(n) comparison algorithm using two pointers -> total complexity of O(n^2)
            for (size_t i = 0; i < nums.size(); i++)
            {

                // pointers
                int j = i+1;
                int k = nums.size()-1;
                int target = -nums[i];
                
                printf("i=%d, j=%d, k=%d\n", i, j, k);
                // skipping duplicate values
                if ( (i > 0) && (nums[i] == nums[i-1]) && (nums[j] == nums[j-1])){
                    continue;
                }

                while (j < k)
                {
                    if ((nums[j] + nums[k]) < target){
                        j++;
                    }
                    else if ((nums[j] + nums[k]) > target){
                        k--;
                    }
                    else {
                        solutions.push_back(std::vector<int>{nums[i], nums[j], nums[k]});
                        break;
                    }
                }
            }

            return solutions;
            
        }

};

int main(int argc, char const *argv[])
{
    std::vector<int> nums = {-1,0,1,2,-1,-4};
    Solution mysol;
    std::vector<std::vector<int>> solution = mysol.threeSum(nums);

    std::cout << "[\n";
    for (size_t i = 0; i < solution.size(); i++)
    {
        char buffer[30];
        snprintf(buffer, sizeof(buffer), "[%d, %d, %d],\n", solution[i][0], solution[i][1], solution[i][2]);
        std::cout << std::string(buffer);
    }
    std::cout << ']' << std::endl;
    
    
    return 0;
}
