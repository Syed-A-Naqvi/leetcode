#include<string>
#include<iostream>

class Solution
{
    public:
    static int equalSubstring(std::string s, std::string t, int maxCost)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        int maxLen = 0;
        int i = 0, j = 0;
        int currCost = 0;

        while(j < s.size())
        {

            currCost += abs(s[j]-t[j]);

            if(currCost <= maxCost)
            {
                maxLen = std::max(maxLen, (j-i+1));
            }
            else
            {
                while(currCost > maxCost)
                {   
                    currCost -= abs(s[i]-t[i]);
                    i++;
                }
            }

            j++;
            
            printf("maxlen = %d\ncurrCost = %d\n", maxLen, currCost);

        }

        return maxLen;
    }
};

int main(int argc, char const *argv[])
{
    std::string s = "abcd";
    std::string t = "bcdf";
    int maxCost = 3;

    printf("s: %s t: %s, Max Substring Within Budget Length: %d\n", s.c_str(), t.c_str(), Solution::equalSubstring(s,t,maxCost));
    return 0;
}
