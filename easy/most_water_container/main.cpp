#include<vector>
#include<cstdio>

int get_min(const int& a, const int& b){
    if(a > b){
        return b;
    }
    else{
        return a;
    }
}

int max_area(std::vector<int>& bars){

    // pointers to the first and last elements
    int i = 0;
    int j = bars.size()-1;

    // default max area is the area between first and last bars
    int max_area = get_min(bars[i],bars[j])*(j-i);
    int max_lower = i;
    int max_upper = j;
    printf("Current max area = %d at bars[i=%d] = %d and bars[j=%d] = %d\n\n", max_area, i,bars[i],j,bars[j]);

    //calculating max area
    while(i < j){

        // step 1: determine index of bar with minimum height and decrement/increment index
        if(bars[i] == get_min(bars[i], bars[j])){
            printf("bars[i=%d] = %d <= %d = bars[j=%d]\n",i,bars[i],bars[j],j);
            printf("incrementing i...\n");
            i++;
            printf("bars[i=%d] = %d, bars[j=%d] = %d\n",i,bars[i],j,bars[j]);
        }
        else{
            printf("bars[j=%d] = %d < %d = bars[i=%d]\n",j,bars[j],bars[i],i);
            printf("decrementing j...\n");
            j--;
            printf("bars[i=%d] = %d, bars[j=%d] = %d\n",i,bars[i],j,bars[j]);
        }

        // Calculate new area
        int new_area = get_min(bars[i],bars[j])*(j-i); 

        if (new_area > max_area){
            max_area = new_area;
            max_lower = i;
            max_upper = j;
            printf("New max area = %d at bars[i=%d] = %d and bars[j=%d] = %d\n\n", max_area, i,bars[i],j,bars[j]);
        }
        else{
            printf("Area = %d at bars[i=%d] = %d and bars[j=%d] = %d /> current max area = %d.\n", new_area, i,bars[i],j,bars[j],max_area);
            printf("max area not updated...\n\n");
        }

    }

    printf("max area = %d at bars[i=%d] = %d and bars[j=%d] = %d\n\n", max_area, max_lower,bars[max_lower],max_upper,bars[max_upper]);
    return max_area;

}

int main(int argc, char const *argv[])
{
    std::vector<int> input = {1,8,12,10,4,6,2,5,4,58,3,7,16};

    return max_area(input);
}
