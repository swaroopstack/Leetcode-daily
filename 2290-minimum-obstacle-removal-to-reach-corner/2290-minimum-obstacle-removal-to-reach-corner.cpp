class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        vector<pair<int,int>> directions{{0,1},{0,-1},{1,0},{-1,0}};
        deque<pair<int,int>> dq;
        vector<vector<int>> dist(grid.size(),vector<int>(grid[0].size(),1e9));
        dist[0][0]=0;
        dq.push_front({0,0});
        while(!dq.empty()){
            int i=dq.front().first;
            int j=dq.front().second;
            dq.pop_front();
            for(auto it:directions){
                int nr=i+it.first;
                int nc=j+it.second;
                if(nr<0 || nr>=grid.size() || nc<0 || nc>=grid[0].size()){
                    continue;
                }
                int cost=grid[i][j];
                if(dist[i][j]+cost<dist[nr][nc]){
                    dist[nr][nc]=dist[i][j]+cost;
                    if(cost==0){
                        dq.push_front({nr,nc});
                    }
                    else{
                        dq.push_back({nr,nc});
                    }
                }
            }
        }
        int n=grid.size();
        int m=grid[0].size();
        return dist[n-1][m-1];
    }
};