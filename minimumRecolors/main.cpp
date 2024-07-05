#include "../cusutils.hpp"
#include<cstdlib>
#include<cstdio>
#include<string>

class Solution {
public:
    static int minimumRecolors(std::string blocks, int k) {
        
        int maxBCount = 0;

        for (int i = 0; i < k; i++)
        {
            if(blocks[i] == 'B') maxBCount++;   
        }

        printf("Original String = %s\n", blocks.c_str());

        int c = maxBCount;
        int start = 0;
        int end = k-1;
        while (end < blocks.size())
        {
            printf("start = %d, end = %d, consecutive blocks = %s\n", start, end, blocks.substr(start, k).c_str());
            printf("max B count = %d\n\n", maxBCount);

            if( (blocks[start] == 'B') ){ c--;}
            start++;
            end++;
            if( (blocks[end] == 'B') ){ c++;}

            if(c > maxBCount)
            {
                maxBCount = c;
            }
        }

        return k-maxBCount;

    }
};

int main(int argc, char const *argv[])
{
    std::string blocks = "WBB";
    int k = 1;
    printf("minimum operations to get k = %d consecutive black blocks: %d\n", k, Solution::minimumRecolors(blocks, k));
    return 0;
}
