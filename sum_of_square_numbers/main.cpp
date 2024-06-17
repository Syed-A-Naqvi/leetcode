#include <iostream>
#include <cstdio>
#include <cmath>

class Solution {
    public:
        bool judgeSquareSum(int c) {
            
            int a = 1;
            int b = 0;

            if ( (sqrt(c) - floor(sqrt(c))) == 0)
            {
                b = int(sqrt(c)) - 1;
            }
            else
            {
                b = int(floor(sqrt(c)));
            }
            
            while ( !( a > b ) )
            {
                if( (pow(a,2) + pow(b,2)) == c)
                {
                    return true;
                }
                else if ((pow(a,2) + pow(b,2)) > c)
                {
                    b--;
                }
                else{
                    a++;
                }
            }

            return false;

        }
};

int main(int argc, char const *argv[])
{
    int c = 100;
    Solution* s1 = new Solution();
    printf("Is %d the sum of two square numbers? %d\n", c, s1->judgeSquareSum(c));
    return 0;
}

