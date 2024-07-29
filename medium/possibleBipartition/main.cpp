#include "../../cusutils.hpp"
#include <queue>

class Solution{

    public:
        static bool possibleBipartition(int n, std::vector<std::vector<int>>& dislikes) {
            
            if(dislikes.size() == 0){return true;}

            // storing the graph structure
            std::vector<std::vector<int>> graph(n+1);
            for(std::vector<int>& d : dislikes)
            {
                graph[d[0]].push_back(d[1]);
                graph[d[1]].push_back(d[0]);
            }

            for (int i = 0; i < graph.size(); i++)
            {
                printf("%d -> %s\n", i, vec_to_string(graph[i]).c_str());
            }
            

            // storing the node group labels
            std::vector<int> labels(n+1,-1);
            // ignoring 0th index
            labels[0] = 1;
            
            // bfs queue
            std::queue<int> q;

            // initialize a random node to a random binary group (0 or 1)
            labels[1] = 1;

            // start bfs
            q.push(1);

            int count = 1;
            while(!q.empty())
            {
                int node = q.front();
                q.pop();
                printf("%d\n",node);

                for (int& adj : graph[node])
                {   
                    if(labels[adj] == labels[node])
                    {
                        return false;
                    }
                    else if (labels[adj] == -1)
                    {
                        labels[adj] = 1-labels[node];
                        q.push(adj);
                        count++;
                    }
                }

                if(q.empty() && count < n)
                {
                    for (int i = 0; i < n+1; i++)
                    {
                        if(labels[i] == -1)
                        {
                            labels[i] = 1;
                            q.push(i);
                            count++;
                            break;
                        }
                    }
                }

                printf("%s\n", vec_to_string(labels).c_str());
                
            }

            return true;

        }
};


int main(int argc, char const *argv[])
{

    std::vector<std::vector<int>> dislikes = {{1,2},{3,4},{4,5},{3,5}};
    printf("%d\n", Solution::possibleBipartition(5, dislikes));
    return 0;
}

