class Solution {
public:
    int solve(int i,vector<string>& strs, int m, int n,vector<vector<vector<int>>>& dp){
        if(i==strs.size()){
            return 0;
        }
        if(dp[i][m][n]!=-1) return dp[i][m][n];

        int skip=solve(i+1,strs,m,n,dp);
        int zero=0;
        int ones=0;
        for(char c: strs[i]){
            if(c=='0'){
                zero++;
            }
            else{
                ones++;
            }
        }
        int take=0;
        if(zero<=m && ones<=n){
            take=1+solve(i+1,strs,m-zero,n-ones,dp);
        }
        return dp[i][m][n]=max(take,skip);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int k=strs.size();
        vector<vector<vector<int>>> dp(
            k,
            vector<vector<int>>(
                m + 1,
                vector<int>(n + 1, -1)
            )
        );
        return solve(0,strs,m,n,dp);
    }
};