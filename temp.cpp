#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include "./cusutils.hpp"

struct VectorHasher
{
    std::size_t operator()(const std::vector<int>& vec) const {
        std::size_t sum = 0;
        std::size_t t = 0;

        for (auto& n : vec) {
            t = n*n;
            sum += t;
        }

        // sum ^= 0x9e3779b9;
        // sum %= 1000;

        return sum;
    }
};


int main(int argc, char const *argv[])
{
    std::vector<std::vector<int>> vectors = {
        {-100, 50, 50},
        {2,1,-3},
        {-1000, 500, 500},
        {-10000, 5000, 5000},
        {-50000, 25000, 25000},
        {-500, -300, 800},
        {-5000, -3000, 8000},
        {-25000, -15000, 40000},
        {-800, 400, 400},
        {-8000, 4000, 4000},
        {-3, 1, 2}
    };

    std::vector<std::size_t> hashes;
    VectorHasher hasher;

    for (auto v : vectors){
        hashes.push_back(hasher(v));
    }

    for (int i = 0; i < hashes.size(); i++)
    {
        for (int j = i+1; j < hashes.size(); j++)
        {
            if (hashes[i] == hashes[j])
            {
                std::cout << "Duplacate hashes found: " + vec_to_string(vectors[i]) + "->" + std::to_string(hashes[i]) + " and " + vec_to_string(vectors[j]) + "->" + std::to_string(hashes[j]) << std::endl;
                break;
            }
            
        }
        
    }

    std::cout << vec_to_string(hashes) << std::endl;

    return 0;
}

