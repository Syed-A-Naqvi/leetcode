#include <iostream>
#include <vector>
#include <cstdio>

class Solution {
    public:
        std::vector<int> twoSum(const std::vector<int>& numbers, int target){
            
            int i = 0;
            int j = numbers.size()-1;

            while (i < j)
            {
                int value = target - numbers[i];
                if (numbers[j] > value)
                {
                    j--;
                }
                else if (numbers[j] < value)
                {
                    i++;
                }
                else
                {
                    return std::vector<int>{i+1, j+1};
                }
            }

            return std::vector<int>{0, 0};
        }

};

int main(int argc, char const *argv[])
{
    Solution mysol = Solution();

    std::vector<int> result = mysol.twoSum(std::vector<int>{1,2,3,4}, 3);

    printf("[%d, %d]\n", result[0], result[1]);

    return 0;
}
