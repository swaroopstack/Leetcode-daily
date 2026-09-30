class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n,1e9);
        dist[src]=0;
        for(int i=0;i<=k;i++){
            vector<int> temp=dist;
            for(auto &it:flights){
                int u=it[0];
                int v=it[1];
                int w=it[2];
                if(dist[u]!=1e9 && dist[u]+w<dist[v]){
                    temp[v]=min(temp[v],dist[u]+w);
                }
            }
            dist=temp;
        }
        return dist[dst]==1e9? -1:dist[dst];
    }
};