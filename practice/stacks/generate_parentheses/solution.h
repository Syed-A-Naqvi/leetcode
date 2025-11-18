#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <string>

class Solution
{
    private:
        std::vector<std::string> stack;
        std::vector<std::string> results;
        void backtrack(int openN, int closedN, int n);

    public:
        Solution(/* args */);
        ~Solution();
        std::vector<std::string> generateParenthesis(int n);
};

#endif