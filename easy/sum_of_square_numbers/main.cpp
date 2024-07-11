#include <iostream>
#include <cstdio>
#include <cmath>

class Solution {
    public:
        bool judgeSquareSum(int c) {
            
            double b = sqrt(c);

            if(fmod(b, 1) == 0 )
            {
                return true;
            }
            else
            {
                b = int(b);
            }

            double min = 0;

            while (b > min)
            {
                min = sqrt(c-(b*b));

                if( fmod(min,1) == 0)
                {
                    return true;
                }
                else
                {
                    b--;
                }
            }

            return false;

        }
};

int main(int argc, char const *argv[])
{

    int c = 6;
    Solution* s1 = new Solution();

    if (s1->judgeSquareSum(c))
    {
        printf("%d is the sum of two square numbers.\n", c);
    }
    else
    {
        printf("%d is NOT the sum of two square numbers.\n", c);
    }
    


    return 0;
}

