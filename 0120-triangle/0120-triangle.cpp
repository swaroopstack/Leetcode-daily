class Solution {
public:
    long long solve(int i,int j,vector<vector<int>> &triangle,vector<vector<long long>> &dp){
        if(i==triangle.size()-1){
            return triangle[i][j];
        }
        if(dp[i][j]!=LLONG_MAX){
            return dp[i][j];
        }
        long long down=solve(i+1,j,triangle,dp);
        long long right=solve(i+1,j+1,triangle,dp);
        return dp[i][j]=triangle[i][j]+min(down,right);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<long long>> dp(n, vector<long long>(n, LLONG_MAX));
        return solve(0,0,triangle,dp);
    }
};