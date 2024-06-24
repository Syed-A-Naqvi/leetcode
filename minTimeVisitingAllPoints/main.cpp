#include<cstdlib>
#include<cstdio>
#include<vector>

using namespace std;

class Solution
{
    public:
        static int minTimeToVisitAllPoints(std::vector<std::vector<int>>& points){
        
            int seconds = 0;

            for(int i = 1; i < points.size(); i++){

                int tHorizontal = points[i][0] - points[i-1][0];
                int tVertical = points[i][1] - points[i-1][1];

                seconds += std::max( std::abs(tVertical), std::abs(tHorizontal));
            }
            return seconds;
        }

};

int main(int argc, char const *argv[])
{
    std::vector<std::vector<int>> v = {{0,0},{3,4},{1,5}};

    int time = Solution::minTimeToVisitAllPoints(v);

    printf("%d seconds\n", time);

    return 0;
}

