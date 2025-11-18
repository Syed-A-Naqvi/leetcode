#include "stack_operations.h"
#include <vector>
#include <string>
#include <cstdio>


int main(int argc, char const *argv[])
{

    std::vector<std::string> tokens = {"1","2","+","3","*","4","-"};

    printf("answer = %i\n", Solution().evalRPN(tokens));

    return 0;
}