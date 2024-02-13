#include<vector>
#include<cstdlib>

int* max_subarray_sum(const std::vector<int>& array){        

    // beginning and end of subarray
    int i = 0;
    int j = 0;

    // maximum subarray encountered so far
    int* max_subarray = new int[3];
    max_subarray[0] = 0;
    max_subarray[1] = i;
    max_subarray[2] = j;

    // previous subarray
    int prev_sum = 0;

    while(j < array.size()){

        if(array[j] + prev_sum > array[j]){
            prev_sum = array[j] + prev_sum;
            if(prev_sum > max_subarray[0]){
                max_subarray[0] = prev_sum;
                max_subarray[1] = i;
                max_subarray[2] = j;
            }
            j++;
        }
        else{
            i = j;
            prev_sum = array[j];
            
        }
    }    

}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
