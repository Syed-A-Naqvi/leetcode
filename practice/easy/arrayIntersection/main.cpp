#include "../cusutils.hpp"
#include <cstdio>
#include<algorithm>
#include<unordered_set>


class Solution
{
    public:
    // static std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2)
    // {
    //     std::sort(nums1.begin(), nums1.end());
    //     std::sort(nums2.begin(), nums2.end());

    //     std::vector<int> intersection;
        
    //     for (int i = 0, j = 0; i < nums1.size() && j < nums2.size();)
    //     {
    //         if ((nums1[i] == nums2[j]))
    //         {
    //             if ( intersection.empty() || (nums1[i] != *(intersection.end()-1)) )
    //             {
    //                 intersection.push_back(nums1[i]);
    //             }
    //             i++;
    //             j++;
    //         }
    //         else if ((nums1[i] < nums2[j]))
    //         {
    //             i++;
    //         }
    //         else
    //         {
    //             j++;
    //         }
    //     }

    //     return intersection;
        
    // }

    // better solution
    static std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        std::vector<int>& smaller = (nums1.size() > nums2.size()) ? nums2 : nums1;
        std::vector<int>& larger = (nums1.size() > nums2.size()) ? nums1 : nums2;
        std::unordered_set<int> set1(larger.begin(), larger.end());
        std::unordered_set<int> intersection;

        for(int num : smaller)
        {
            if(set1.count(num))
            {
                intersection.insert(num);
            }
        }
        return std::vector<int>(intersection.begin(),intersection.end());
    }
};

int main(int argc, char const *argv[])
{
    std::vector<int> nums1 = {9,4,9,8,4};
    std::vector<int> nums2 = {4,9,5};
    std::vector<int> intersection = Solution::intersection(nums1,nums2);

    printf("%s\n",vec_to_string(intersection).c_str());
    return 0;
}

