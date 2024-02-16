#include<vector>
#include<cstdlib>
#include<cstdio>


void print_max_subarray(const std::vector<int>& array){
    
    int sum = 0;
    printf("max sum subarray: [");
    for (int num: array)
    {
        printf(" %d ", num);
        sum += num;
    }
    printf("]\nmax sum = %d\n", sum);
    
}

std::vector<int> max_subarray_sum(const std::vector<int>& array){        

    // beginning and end of subarray with max sum
    int start = 0;
    int end = 0;
    // array interator
    int j = 0;

    // storing current sum, and max sum
    int running_sum = array[start];
    int max_sum = running_sum;

    while(j < array.size()){
        
        // if current element is greater than running sum + current element, reset running sum to current element
        // set i to index of current element, disregarding previous array
        if(array[j] > array[j] + running_sum){
            start = j;
            end = j;
            running_sum = array[j];
        }
        // if current element + running sum is greater than current element
        // add current element to running sum
        else{
            running_sum += array[j];
        }

        // if running sum is greater than current max, set new max
        // mark current j index as end of potential max subarray
        if( running_sum > max_sum ){
            max_sum = running_sum;
            end = j;
        }

        j++;

    }

    std::vector<int> max_subarray;

    for (int x = start; x <= end ; x++)
    {
        max_subarray.push_back(array[x]);
    }

    return max_subarray;

}

int main(int argc, char const *argv[])
{
    std::vector<int> array = {-2,1,-2,4,-1,2,1,-5,4};

    array = max_subarray_sum(array);

    print_max_subarray(array);

    return 0;
}
