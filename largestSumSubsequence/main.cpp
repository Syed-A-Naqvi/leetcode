#include<cstdio>
#include<algorithm>
#include<utility>
#include "../cusutils.hpp"


class Solution{
    public:
        static std::vector<int> maxSubsequence(std::vector<int>& nums, int k){
            
            //create copy O(n)
            std::vector<std::pair<int,int>> temp;
            for(int i = 0; i < nums.size(); i++){
                temp.push_back(std::pair<int,int>(nums[i],i));
            }

            //sort copy O(nlogn)
            std::sort(temp.begin(), temp.end(), [](const std::pair<int,int>& a, const std::pair<int,int>& b){
                return a.first > b.first;
            });

            //finding temp elements
            while(temp.size() != k){
                temp.pop_back();
            }

            //correcting subsequence order
            std::sort(temp.begin(), temp.end(), [](const std::pair<int,int>& a, const std::pair<int,int>& b){
                return a.second < b.second;
            });

            //build temp O(n)
            std::vector<int> answer;
            for(auto& item: temp){
                answer.push_back(item.first);
            }
            
            return answer;

        }
};

int main(int argc, char const *argv[])
{
    std::vector<int> nums = std::vector<int>({-1,-2,3,4});
    std::string answer = vec_to_string(Solution::maxSubsequence(nums, 3));

    printf("%s\n", answer.c_str());
    

    return 0;
}
