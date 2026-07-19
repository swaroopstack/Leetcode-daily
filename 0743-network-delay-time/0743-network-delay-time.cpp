class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n + 1);
        for (auto edge : times) {
            int source = edge[0];
            int destination = edge[1];
            int weight = edge[2];
            graph[source].push_back({destination, weight});
        }
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            minheap;

        minheap.push({0, k});
        while (!minheap.empty()) {
            auto current = minheap.top();
            minheap.pop();
            int currentdistance = current.first;
            int currentnode = current.second;
            if (currentdistance > dist[currentnode])
                continue;
            for(auto &[nextnode,edgew]:graph[currentnode]){
                int newdist=currentdistance+edgew;
                if(newdist<dist[nextnode]){
                    dist[nextnode]=newdist;
                    minheap.push({newdist,nextnode});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if (dist[i] == INT_MAX)
                return -1;

            ans = max(ans, dist[i]);
        }
        return ans;
    }
};