#include "../cusutils.hpp"
#include <cstdlib>
#include <cstdio>

class Solution
{
    public:
    static std::string firstPalindrome(std::vector<std::string>& words)
    {
        for(auto& word : words)
        {
            bool flag = 1;
            for (int i = 0,j = word.size()-1; i < j; i++,j--)
            {
                if(word[i] != word[j])
                {
                    flag = 0;
                }
            }
            if(flag)
            {
                return word;
            }
        }

        return "";
    }
};

int main(int argc, char const *argv[])
{
    std::vector<std::string> words = {"abc","car","cool","racecar","ada"};
    printf("%s\n", Solution::firstPalindrome(words).c_str());
    return 0;
}
