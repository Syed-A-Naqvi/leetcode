#include"../../cusutils.hpp"
#include<unordered_map>
#include<list>

class TweetCounts {

public:

    static std::unordered_map<std::string, int> denominations;

    std::unordered_map<std::string,std::list<int>> record;

    TweetCounts() {
        
    }
    
    void recordTweet(std::string tweetName, int time) {

        if(this->record.find(tweetName) == this->record.end())
        {
            this->record[tweetName].push_front(time);
        }
        else
        {
            if(time < this->record[tweetName].front())
            {
                this->record[tweetName].push_front(time);
            }
            else if (time > this->record[tweetName].back())
            {
                this->record[tweetName].push_back(time);
            }
            else
            {
                auto record_it = this->record[tweetName].begin();
                while(*(++record_it) < time){}
                this->record[tweetName].insert(record_it, time);
            }
        }

        printf("%s: ", tweetName.c_str());
        for(auto& t : this->record[tweetName])
        {
            printf("%d ->", t);
        }
        printf("\n");
    }
    
    std::vector<int> getTweetCountsPerFrequency(std::string freq, std::string tweetName, int startTime, int endTime) {
        
        std::vector<int> frequencies;
        int chunks = this->denominations[freq];

        std::list<int>::iterator record_it = this->record[tweetName].begin();
    
        for (int L = startTime, R = startTime+chunks; L <= endTime; L+=chunks, R+=chunks)
        {
            if(R > endTime){R = endTime+1;}

            int count = 0;

            while(record_it != this->record[tweetName].end() && *(record_it) < R)
            {

                if( (*(record_it) >= L) && (*(record_it) < R ))
                {
                    count++;
                    printf("L = %d <= record_it = %d < R = %d, count = %d\n", L, *(record_it), R, count);
                }
                record_it++;
            }
            
            frequencies.push_back(count);
        }

        return frequencies;

    }
};

std::unordered_map<std::string, int> TweetCounts::denominations = {
    {"minute", 60},
    {"hour", 3600},
    {"day", 86400}
};

int main(int argc, char const *argv[])
{
    TweetCounts tweetCounts;
    tweetCounts.recordTweet("tweet3",0);
    tweetCounts.recordTweet("tweet3",60);
    tweetCounts.recordTweet("tweet3",10);
    printf("%s\n", vec_to_string(tweetCounts.getTweetCountsPerFrequency("minute","tweet3",0,59)).c_str());
    printf("%s\n", vec_to_string(tweetCounts.getTweetCountsPerFrequency("minute","tweet3",0,60)).c_str());
    tweetCounts.recordTweet("tweet3",120);
    printf("%s\n", vec_to_string(tweetCounts.getTweetCountsPerFrequency("hour","tweet3",0,210)).c_str());
    return 0;
}
