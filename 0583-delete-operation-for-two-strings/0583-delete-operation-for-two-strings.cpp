class Solution {
public:
    int solve(string &word1, string &word2, int i, int j,vector<vector<int>>& dp){
        if(i==word1.size() || j==word2.size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(word1[i]==word2[j]){
            return dp[i][j]=1+solve(word1,word2,i+1,j+1,dp);
        }
        return dp[i][j]=max(
            solve(word1,word2,i+1,j,dp),
            solve(word1,word2,i,j+1,dp)
        );
    }
    int minDistance(string word1, string word2) {
       int n=word1.size();
       int m=word2.size();
       vector<vector<int>> dp(n,vector<int>(m,-1));
       int common= solve(word1,word2,0,0,dp); 
       if(n==m){
            if(common<n){
                return 2*(n-common);
            }
            else{
                return 0;
            }
        }
       else if(n<m){
            if(common<n){
                int ans=n-common;
                ans+=m-common;
                return ans;
            }
            else{
                return m-common;
            }
       }
       else{
            if(common<m){
                int ans=m-common;
                ans+=n-common;
                return ans;
            }
            else{
                return n-common;
            }
       }
       return common;
    }
};