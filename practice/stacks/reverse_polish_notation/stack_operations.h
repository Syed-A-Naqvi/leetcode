#ifndef STACK_OPERATIONS_H
#define STACK_OPERATIONS_H

#include<string>
#include<vector>


class Solution {

    public:
        Solution() = default;
        ~Solution() = default;
        int evalRPN(std::vector<std::string> &tokens);
};

#endif