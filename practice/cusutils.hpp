#ifndef CUSUTILS_HPP
#define CUSUTILS_HPP

#include<string>
#include<vector>

template<typename T>
std::string vec_to_string(const std::vector<T>& vec)
{
    
    if(vec.empty())
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