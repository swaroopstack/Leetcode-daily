class Solution {
public:
    void dfs(int u,unordered_map<int,vector<pair<int,int>>>& adj,vector<int>& visited,int & ans){
        visited[u]=true;
        for(auto &p: adj[u]){
            int v=p.first;
            int d=p.second;
            ans=min(ans,d);
            if(!visited[v]){
                dfs(v,adj,visited,ans);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>> adj;
        vector<int> visited(n+1,false);
        for(auto &node:roads){
            int u=node[0];
            int v=node[1];
            int w=node[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        int ans=INT_MAX;
        dfs(1,adj,visited,ans);
        return ans;
    }
};