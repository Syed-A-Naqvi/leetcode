#include"../../cusutils.hpp"
#include <cstdio>

class Solution {
public:
    static std::vector<int> minDeletion(std::vector<int>& nums) {
        
        // could use an integer to keep track of the last element in the answers array
        // and another to keep track of the current size of the answers array instead of creating an actual answers array
        std::vector<int> answer = {nums[0]};
        int count = 0;

        for (int i = 1; i < nums.size(); i++)
        {
            if( ((answer.size()-1)%2 == 0) && (nums[i] == answer[answer.size()-1]) )
            {
                count++;
            }
            else
            {
                answer.push_back(nums[i]);
            }
        }

        if(answer.size()%2 != 0){
            answer.pop_back();
            count++;
        }
        
        // return count;
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    std::vector<int> nums = {1,1,2,2,3,4,4,4};
    std::vector<int> answer = Solution::minDeletion(nums);
    printf("Original array = %s\n", vec_to_string(nums).c_str());
    printf("Beautiful array = %s\n", vec_to_string(answer).c_str());
    return 0;
}
