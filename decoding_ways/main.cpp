#include<cstdlib>
#include<cstdio>
#include<string>

int decoding_ways(std::string s){
    
    // returning 0 if the string is empty
    if(s.length() < 1){
        return 0;
    }

    // returning 0 if the leading digit is 0 as there is no character mapping for single 0
    if(s[0] == '0'){
        return 0;
    }

    // returning 1 as there is only one possible decoding for a single digit
    if(s.length() == 1){
        return 1;
    }

    // ***dynamic programming***
    // will keep track of the number of ways to decode digits up to i-1 position and i-2 position
    int val1 = 1;
    int val2 = 1;

    // calculating the number of ways by iterating through string and updating val1 and val2
    for (int i = 1; i < s.length(); i++)
    {
        // digit at current i position
        int d1 = s[i] - '0';
        // combining digits at positions i-1 and i to create a 2 digit number
        int d2 = (s[i-1] - '0')*10 + d1;
        // initialize number of ways to decode for current index to 0
        int val = 0;

        // if the current digit is 1-9 this digit can be decoded individually
        // number of ways to decode string up to i will be the same as the number of ways up to i-1
        if(d1 >= 1){
            // val just becomes val1
            val += val1;
        }
        // if combining i-1 digit with ith digit creates a number in [10,26], both digits can be
        // decoded together
        // so number of was to decode string up to i will be the same as number of ways to decode
        // string up to i-2
        if(d2 >= 10 && d2 <= 26){
            // increase val by val2
            val += val2;
        }

        // val2 set to count for digits up to i-1, val1 set to count for digits up to i
        val2 = val1;
        val1 = val;
        // during next iteration i = i+1 so val2 tracks up to i-2 and val1 tracks i-1
    }

    return val1;
    
}


int main(int argc, char const *argv[])
{

    printf("Input: \"226\", Number of decodings: %d\n", decoding_ways("226"));

    return 0;
}
