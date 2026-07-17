class Solution {
public:
    void dfs(vector<vector<int>>& adj,int source,int destination, vector<bool>& visited){
        visited[source]=true;
        if(source==destination) return ;
        for(int near:adj[source]){
            if(!visited[near]){
                dfs(adj,near,destination,visited);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source==destination) return true;
        vector<vector<int>> adj(n);
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);   
        }
        vector<bool> visited(adj.size(),false);
        dfs(adj,source,destination,visited);
        if(!visited[destination]){
            return false;
        }
        return true;
    }
};