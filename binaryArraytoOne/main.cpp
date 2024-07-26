#include"../cusutils.hpp"

class Solution {
    public:
        static int minOperations(std::vector<int>& nums) {
            int operations = 0;

            for(int i = nums.size()-1; i > 0; i--)
            {
                if(nums[i-1] != nums[i])
                {
                    operations++;
                }
            }

            if(nums[0] == 1) {return operations;}
            else {return ++operations;}
        }
};

int main(int argc, char const *argv[])
{
    std::vector<int> nums = {1,1,1,1,1,1,1,1,1,1,1};

    printf("%d\n", Solution::minOperations(nums));

    return 0;
}
