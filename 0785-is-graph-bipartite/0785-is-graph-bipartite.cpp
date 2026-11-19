
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<int> vis(v,-1);

        for(int i=0;i<v;i++){
            if(vis[i]==-1){
                queue<int> q;
                q.push(i);
                vis[i]=0;

                while(!q.empty()){
                    int node=q.front();
                    q.pop();

                    for(int nbr:graph[node]){
                        if(vis[nbr]==-1){
                            vis[nbr]=!vis[node];
                            q.push(nbr);
                        }
                        else if(vis[nbr]==vis[node]){
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};
