#include<cstdlib>
#include<cstdio>
#include<vector>
#include<cmath>

class Solution {
    public:
        std::vector<int> numberGame(std::vector<int>& nums) {

            sort(nums);

            for (int i = 1; i < nums.size(); i+=2)
            {
                int temp = nums[i];
                nums[i] = nums[i-1];
                nums[i-1] = temp;
            }

            return nums;
        }

    private:
        void sort(std::vector<int>& array){
            for (int i = 0; i < array.size(); i++)
            {
                int minIndex = i;
                for (int j = i + 1; j < array.size(); j++)
                {
                    if (array[j] < array[minIndex])
                    {
                        minIndex = j;
                    }
                }

                if(minIndex != i)
                {
                    int temp = array[i];
                    array[i] = array[minIndex];
                    array[minIndex] = temp;
                }

            }

        }

};

int main(int argc, char const *argv[])
{
    std::vector<int> v = {3,2,5,4};
    
    Solution sol;

    v = sol.numberGame(v);

    printf("[");
    for (int i = 0; i < v.size(); i++)
    {
        if (i == (v.size()-1))
        {
            printf("%d", v[i]);
        }
        else
        {
            printf("%d, ", v[i]);
        }
        
    }    
    printf("]\n");
    
    return 0;
}
