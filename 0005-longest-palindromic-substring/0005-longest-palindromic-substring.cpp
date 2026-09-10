class Solution {
public:
    string ans="";
    int ispalindrome(int l,int r,string& s,vector<vector<int>>& dp){
        if(l>=r){
            return 1;
        }
        if(s[l]!=s[r]){
            return 0;
        }
        if(dp[l][r]!=-1){
            return dp[l][r];
        }
        return dp[l][r]=ispalindrome(l+1,r-1,s,dp);
    }
    
    string longestPalindrome(string s) {
        vector<vector<int>>dp(s.size(),vector<int>(s.size(),-1));
        int n = s.size();
        for (int l = 0; l < n; l++) {
            for (int r = l; r < n; r++) {

                if (ispalindrome(l, r, s, dp)) {
                    if (r - l + 1 > ans.size()) {
                        ans = s.substr(l, r - l + 1);
                    }
                }
            }
        }
        return ans;
    }
};