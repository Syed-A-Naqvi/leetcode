#include<vector>
#include<algorithm>
#include"../../cusutils.hpp"

class Solution
{
    public:

        static int lastStoneWeight(std::vector<signed char>& stones)
        {
            std::vector<signed char> v;
            std::vector<signed char>* prev = &stones;
            std::vector<signed char>* next = &v;
            std::vector<signed char>* temp;
            signed char largest, mid, new_stone;
            bool added;

            printf("%s \n", vec_to_string(*prev).c_str());

            std::sort(stones.begin(), stones.end());

            printf("%s \n", vec_to_string(*prev).c_str());

            while(prev->size()>1)
            {
                largest = prev->size()-1;
                mid = largest/2;
                new_stone = (*prev)[largest] - (*prev)[mid];
                added = 0;
                printf("largest = %d, mid = %d, new_stone = %d\n", largest, mid, new_stone);

                for (signed char i = 0; i < prev->size()-1; i++)
                {
                    if((i == mid))
                    {
                        continue;
                    }

                    if((*prev)[i] < new_stone)
                    {
                        next->push_back((*prev)[i]);
                    }
                    else
                    {
                        if((new_stone != 0) && !added)
                        {
                            next->push_back(new_stone);
                            added = 1;
                        }
                        next->push_back((*prev)[i]);
                    }
                }

                if(!added)
                {
                    next->push_back(new_stone);
                }

                temp = prev;
                prev = next;
                next = temp;
                next->resize(0);

                printf("%s \n", vec_to_string(*prev).c_str());
                
            }

            if(prev->empty())
            {
                return 0;
            }
            else
            {
                return (*prev)[0];
            }
            
        }
};

int main(int argc, char const *argv[])
{
    
    std::vector<signed char> stones = {1,1,2,3,5,8,13,21,34,55,89,14,23,37,61,98};

    printf("%d\n", Solution::lastStoneWeight(stones));

    return 0;
}
