#include "solution.h"
#include <vector>
#include <string>
#include <iostream>

int main(int argc, char const *argv[])
{
    
    Solution mysol;
    int n = 4;

    std::vector<std::string> result = mysol.generateParenthesis(n);

    for(auto &s : result){
        std::cout << "[" << s << "]" << std::endl;
    }

    return 0;
}

