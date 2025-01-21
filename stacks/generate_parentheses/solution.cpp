#include "solution.h"
#include <vector>
#include <string>

Solution::Solution() = default;
Solution::~Solution() = default;

void Solution::backtrack(int openN, int closedN, int n) {
    
    if(openN == n && closedN == n){
        std::string valid_combo = "";
        for (auto &s : this->stack) {
            valid_combo.append(s);
        }
        this->results.push_back(valid_combo);
        return;   
    }

    if(openN < n){
        this->stack.push_back("(");
        this->backtrack(openN+1, closedN, n);
        this->stack.pop_back();
    }

    if(closedN < openN){
        this->stack.push_back(")");
        this->backtrack(openN, closedN + 1, n);
        this->stack.pop_back();
    }

}

std::vector<std::string> Solution::generateParenthesis(int n){

    this->backtrack(0, 0, n);

    return this->results;

}