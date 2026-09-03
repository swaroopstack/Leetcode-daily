class Solution {
public:

    int solve(int i,int j,string word1, string word2,vector<vector<int>>& dp){
        if(i>=word1.size()){
            return word2.size()-j;
        }
        if(j>=word2.size()){
            return word1.size()-i;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans;
        if(word1[i]==word2[j]){
           return  dp[i][j]=solve(i+1,j+1,word1,word2,dp);
        }
        else{
            ans= min({
                1+solve(i,j+1,word1,word2,dp),// insertion
                1+solve(i+1,j,word1,word2,dp), // deletion
                1+solve(i+1,j+1,word1,word2,dp) //replace
            });
        }
        return dp[i][j]=ans;
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(),vector<int>(word2.size(),-1));
        return solve(0,0,word1,word2,dp);
    }
};