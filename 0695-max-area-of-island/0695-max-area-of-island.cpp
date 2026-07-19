class Solution {
public:
    vector<pair<int,int>> dirs{{-1,0},{1,0},{0,-1},{0,1}};
    int ans=0;
    int dfs(int currentrow,int currentcol,vector<vector<int>>& grid){
        int area=1;
        grid[currentrow][currentcol]=0;
        int rows=grid.size();
        int cols=grid[0].size();
        for(auto dir:dirs){
            int nextrow=currentrow+dir.first;
            int nextcol=currentcol+dir.second;
            if(nextrow>=0 && nextrow<rows && nextcol>=0 && nextcol<cols &&
                grid[nextrow][nextcol]==1){

                    area+=dfs(nextrow,nextcol,grid);
            }
        }
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        int maxArea = 0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1){
                    int currentArea = dfs(i, j, grid);
                    maxArea = max(maxArea, currentArea);
                }
            }
        }
        return maxArea;
    }
};