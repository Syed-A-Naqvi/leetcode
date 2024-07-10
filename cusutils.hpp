#ifndef CUSUTILS_HPP
#define CUSUTILS_HPP

#include<string>
#include<vector>

std::string vec_to_string(std::vector<int>& vec)
{
    
    if(vec.size() == 0)
    {
        return "[]";
    }
    else
    {
        std::string result = "[ ";
        for (int i = 0; i < vec.size(); i++)
        {
            if(i>0)
            {
                result += ", ";
            }
            result += std::to_string(vec[i]);
        }
        result += " ]";
        return result;
    }
    
}

#endif