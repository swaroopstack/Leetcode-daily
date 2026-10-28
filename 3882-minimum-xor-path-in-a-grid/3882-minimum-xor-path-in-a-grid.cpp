class Solution {
public:
    int ans;
    int solve(int i, int j,int cost,vector<vector<int>>& grid,vector<vector<vector<int>>> & dp){
        if(i>=grid.size() || j>=grid[0].size()){
            return INT_MAX;
        }
        cost^=grid[i][j];
        if(i==grid.size()-1 && j==grid[0].size()-1){
            return dp[i][j][cost]=ans=min(ans,cost);
        }
        if(dp[i][j][cost]!=-1){
            return dp[i][j][cost];
        }
        int right=solve(i,j+1,cost,grid,dp);
        int down=solve(i+1,j,cost,grid,dp);
        return dp[i][j][cost]=min(down,right);
    }
    int minCost(vector<vector<int>>& grid) {
        ans=INT_MAX;
        vector<vector<vector<int>>> dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(1024,-1)));
        solve(0,0,0,grid,dp);
        return ans;
    }
};