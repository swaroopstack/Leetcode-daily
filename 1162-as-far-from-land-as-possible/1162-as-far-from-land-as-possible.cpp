class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                }
                else{
                    grid[i][j]=INT_MAX;
                }
            }
        }
        vector<pair<int,int>> directions={{-1,0},{1,0},{0,-1},{0,1}};
        int ans=0;
        while(!q.empty()){
            int cr=q.front().first;
            int cc=q.front().second;
            q.pop();
            for(auto dir:directions){
                int nr=cr+dir.first;
                int nc=cc+dir.second;
                if(nr<0 || nr>=rows || nc<0 || nc>=cols){
                    continue;
                }
                if(grid[nr][nc]==INT_MAX){
                    grid[nr][nc]=grid[cr][cc] + 1;
                    ans=max(ans,grid[nr][nc]-1);
                    q.push({nr,nc});
                }
            }
        }
        return ans==0? -1 : ans;
    }
};