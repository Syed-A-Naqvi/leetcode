#include "stack_operations.h"
#include <vector>
#include <string>
#include <unordered_set>

int Solution::evalRPN(std::vector<std::string> &tokens){

    std::vector<int> stack;
    stack.reserve(2);

    for(const auto &token : tokens){
        if(token == "+" || token == "-" || token == "*" || token == "/"){
            
            int b = stack.back();
            stack.pop_back();
            int a = stack.back();
            stack.pop_back();

            if(token == "+") stack.push_back(a+b);
            else if(token == "-") stack.push_back(a-b); 
            else if(token == "*") stack.push_back(a*b); 
            else if(token == "/") stack.push_back(a/b); 

        }
        else{
            stack.push_back(std::stoi(token));
        }
    }

    printf("current size of stack = %i\n", stack.capacity());
    return stack.back();

}