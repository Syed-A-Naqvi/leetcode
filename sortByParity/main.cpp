#include <cstdlib>
#include <cstdio>
#include "../cusutils.hpp"

class Solution
{
    public:
        static std::vector<int> sortArrayByParity(std::vector<int>& nums)
        {
            
            std::vector<int> sorted(nums.size());
            
            for (int i = 0, j = nums.size()-1, x = 0; x <= j; i++)
            {
                if(nums[i]%2 == 0)
                {
                    sorted[x] = nums[i];
                    x++;
                }
                else
                {
                    sorted[j] = nums[i];
                    j--;
                }
            }

            return sorted;
            
        }
};

int main(int argc, char const *argv[])
{
    std::vector<int> unsorted = {3,1,2,4};
    printf("%s\n", vec_to_string(Solution::sortArrayByParity(unsorted)).c_str());
    return 0;
}
