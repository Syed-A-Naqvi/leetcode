#include "../cusutils.hpp"
#include<cstdlib>
#include<cstdio>
#include<string>

class Solution {
public:
    int minOperations(std::string s) {
        
        char v1 = '0';
        char v2 = '1';

        int c1 = 0;
        int c2 = 0;        
        for (int i = 0; i < s.size(); i++)
        {
            if(s[i] != v1){ c1++; }
            if(s[i] != v2){ c2++; }

            if(i%2 == 0)
            {
                v1 = '1';
                v2 = '0';
            }
            else
            {
                v1 = '0';
                v2 = '1';
            }

        }

        if (c1>c2)
        {
            return c2;
        }
        else
        {
            return c1;
        }      
    }

};