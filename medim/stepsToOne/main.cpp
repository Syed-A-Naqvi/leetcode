#include <string>
#include <cstdio>
#include <climits>
#include <vector>
#include <bitset>

class Solution{

    public:
        static int numSteps(std::string s) {
            
            int steps = 0;
            while(s.size() != 1)
            {
                if (s[s.size()-1] == '1')
                {
                    int i = s.size()-1;
                    while(i > -1 && s[i] == '1')
                    {
                        s[i] = '0';
                        i--;
                    }
                    if (i < 0) { s = '1' + s;}
                    else{s[i] = '1';}
                }
                else
                {
                    s.pop_back();
                }

                steps ++;
            }

            return steps;
        }
};

int main(int argc, char const *argv[])
{
    printf("%d\n", Solution::numSteps("1101"));
    return 0;
}
