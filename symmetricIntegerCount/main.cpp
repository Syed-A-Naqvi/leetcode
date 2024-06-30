#include<cstdlib>
#include<cstdio>
#include<string>
#include<cmath>

class Solution{
    
    public:
        
        static int countSymmetricIntegers(int low, int high) {
            
            int count = 0;
            for (int i = low; i <=high; i++)
            {
                std::string digits = std::to_string(i);
                
                if( (digits.size())%2 != 0 )
                {
                    i = static_cast<int>(pow(10,digits.size())-1);

                    if( i > high ){break;}
                    else {continue;}
                }
                
                int lower = 0;
                int upper = 0;
                for (int a=0, b=digits.size()-1; a<b; a++, b--)
                {
                    lower+=static_cast<int>(digits[a]);
                    upper+=static_cast<int>(digits[b]);
                }

                if(upper == lower) {count++;}
            }
            
            return count;
        }
};

int main(int argc, char const *argv[])
{
    printf("%d\n", Solution::countSymmetricIntegers(1200,1230));
    return 0;
}
