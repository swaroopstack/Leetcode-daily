class Solution {
public:
    int ans=0;
    int solve(int i,int j,string s,vector<vector<int>>& dp){
        if(i>=j) return true;
        if(s[i]!=s[j]) return false;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        return dp[i][j]=solve(i+1,j-1,s,dp);
    }
    int countSubstrings(string s) {
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),-1));
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(solve(i,j,s,dp)){
                    ans++;
                }
            }
        }
        return ans;
    }
};