#include<vector>
#include<cstdio>

class Solution {
    public:
        int maxSatisfied(std::vector<int>& customers, std::vector<int>& grumpy, int minutes) {
            
            int maxUnsatisfied = 0;
            int start = 0, end = -1;

            for(int i = 0, j = minutes-1; j < customers.size(); i++,j++)
            {
                int unsatisfied = 0;
                for(int x = i; x <= j; x++)
                {
                    if (grumpy[x])
                    {
                        unsatisfied += customers[x];
                    }
                }

                if (unsatisfied > maxUnsatisfied)
                {
                    maxUnsatisfied = unsatisfied;
                    start = i;
                    end = j;
                }
            }

            if(end != -1)
            {
                for(int i = start; i <= end; i++)
                {
                    grumpy[i] = 0;
                }
            }

            int maxSat = 0;
            for(int i = 0; i < customers.size(); i++)
            {
                if(!grumpy[i])
                {
                    maxSat += customers[i];
                }
            }

            return maxSat;

        }
};

int main(int argc, char const *argv[])
{
    Solution sol = Solution();
    std::vector<int> grumpy = {0,1,0,1,0,1,0,1};
    std::vector<int> customers = {1,0,1,2,1,1,7,5};

    printf("max satisfied = %d\n", sol.maxSatisfied(customers, grumpy, 3));
    return 0;
}
