#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<string>


class Solution{
    public:
        static int countEven(int num){
            
            int count = 0;

            for (int i = 2; i <= num; i++)
            {
                if (i < 10)
                {
                    if(i%2 == 0){count++;}
                }
                else if (i<100)
                {
                    if( ( (i/10) + (i%10) )%2 == 0){count++;}
                }
                else if (i<1000)
                {
                    if( ((i/100) + ((i%100)/10) + ((i%100)%10)) %2 == 0) {count++;}
                }
                else
                {
                    if(( (i/1000) + ((i%1000)/100) + (((i%1000)%100)/10) + (((i%1000)%100)%10) )%2 == 0){count++;}
                }   
            }

            return count;

        }
};


int main(int argc, char const *argv[])
{
    printf("%d\n", Solution::countEven(30));
    return 0;
}
