#include <cstdio>
#include<vector>
#include<utility>
#include<unordered_map>


std::pair<int,int> two_sum(std::vector<int>& array, int target){
    
    // stores numbers encountered so far, will be queried for potential complement
    std::unordered_map<int, int> complements;

    // iterating through the array
    for (size_t i = 0; i < array.size(); i++)
    {
        // determining complement for current array element
        int c = target - array[i];
        
        // if the complement exists as a key return current index and complement index
        auto it = complements.find(c);
        if(it != complements.end()){
            return std::make_pair(complements[c], i);
        }

        // if complement not in map add current array element
        complements[array[i]] = i;
    }

    // if for loop completes return (0,0)
    return std::make_pair(-1,-1);
}

int main(int argc, char const *argv[])
{
    
    // array and target creation
    std::vector<int> array = {3,2,10,11,3,15,1,2,20,1,5};
    int target = 9;

    // extracting pair indecies
    std::pair<int,int> pair = two_sum(array, target);

    // determining if pair found and printing results
    if (pair.first == -1){
        printf("No pair summing to %d was found in the array.\n", target);
    }
    else{
        printf("The pair (%d,%d) was found in the array and sums to %d.\n",
                array[pair.first], array[pair.second], target);
    }

    return 0;
}
