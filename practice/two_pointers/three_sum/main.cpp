#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include "../../cusutils.hpp"

// ------------------ USING HASHING ------------------

// class Solution
// {
//     public:
//         std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
            
//             // sorting the vector in non-decreasing order for easier processing O(nlogn)
//             std::sort(nums.begin(), nums.end());

//             std::unordered_set<std::vector<int>, VectorHasher> solution_set;

//             std::cout << vec_to_string(nums) << std::endl;
            
//             // for each element we run an O(n) comparison algorithm using two pointers -> total complexity of O(n^2)
//             for (size_t i = 0; i < nums.size(); i++)
//             {

//                 // pointers and sum target
//                 int j = i+1;
//                 int k = nums.size()-1;
//                 int target = -nums[i];
                
//                 printf("i=%d, j=%d, k=%d\n", i, j, k);

//                 while (j < k)
//                 {
//                     if ((nums[j] + nums[k]) < target){
//                         j++;
//                     }
//                     else if ((nums[j] + nums[k]) > target){
//                         k--;
//                     }
//                     else {

//                         std::vector<int> solution = {nums[i], nums[j], nums[k]};
//                         solution_set.insert(solution);

//                         // does not matter if we increment j or decrement k, just need the loop to keep moving
//                         j++;
//                     }
//                 }
//             }

//             std::vector<std::vector<int>> solutions;
//             for (auto& v : solution_set){
//                 solutions.push_back(v);
//             }

//             return solutions;
            
//         }

//         struct VectorHasher
//         {
//             std::size_t operator()(const std::vector<int>& vec) const {
//                 std::size_t sum = 0;
//                 std::size_t t = 0;
            
//                 for (auto& n : vec) {
//                     t = n*n;
//                     sum += t;
//                 }
            
//                 return sum;
//             }
//         };

// };


// ------------------ NO HASHING ------------------

class Solution
{
    public:
        std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
            
            // sorting the vector in non-decreasing order for easier processing O(nlogn)
            std::sort(nums.begin(), nums.end());

            std::cout << vec_to_string(nums) << std::endl;

            // solution set
            std::vector<std::vector<int>> solutions;

            if (nums.size() < 3) {
                return solutions;
            }
            
            // for each element we run an O(n) comparison algorithm using two pointers -> total complexity of O(n^2)
            for (size_t i = 0; i < nums.size(); i++)
            {

                if (i > 0 && nums[i] == nums[i-1]){
                    continue;
                }

                // pointers
                int j = i+1;
                int k = nums.size()-1;
                
                printf("i=%d, j=%d, k=%d\n", i, j, k);

                while (j < k)
                {

                    if ( (j > i+1 && nums[j] == nums[j-1]) || ((nums[i] + nums[j] + nums[k]) < 0) ){
                        j++;
                    }
                    else if ( (k < nums.size()-1 && nums[k] == nums[k+1]) || ((nums[i] + nums[j] + nums[k]) > 0) ){
                        k--;
                    }
                    else {
                        solutions.push_back(std::vector<int>{nums[i], nums[j], nums[k]});
                        // does not matter if we increment j or decrement k, just need the loop to keep moving
                        j++;
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
