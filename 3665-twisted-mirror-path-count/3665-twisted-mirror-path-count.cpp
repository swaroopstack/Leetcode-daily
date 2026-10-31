class Solution {
public:
    int mod=1e9+7;
    int n,m;
    int left=0;
    int up=1;

    int solve(vector<vector<int>>& grid, int i, int j,int camefrom,vector<vector<array<int, 2>>>& dp){
        if(i>=m || j>=n){
            return 0;
        }
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(dp[i][j][camefrom]!=-1){
            return dp[i][j][camefrom];
        }
        if(grid[i][j]==1){
            if(camefrom==left){
                return dp[i][j][camefrom]=solve(grid,i+1,j,up,dp);
            }
            else{
                return dp[i][j][camefrom]=solve(grid,i,j+1,left,dp);
            }
        }
        int ans=0;
        ans=(ans+solve(grid,i,j+1,left,dp))%mod;
        ans=(ans+solve(grid,i+1,j,up,dp))%mod;

        return dp[i][j][camefrom]=ans;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<array<int, 2>>> dp(m+1, vector<array<int, 2>>(n, {-1, -1}));

        return solve(grid,0,0,left,dp);
    }
};