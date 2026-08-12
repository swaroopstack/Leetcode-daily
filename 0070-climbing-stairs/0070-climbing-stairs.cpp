class Solution {
public:
    vector<int> dp;
    int solve(int n){
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n]=solve(n-1)+solve(n-2);
    }
    int climbStairs(int n) {
        dp.assign(n+1,-1);
        dp[0]=1;
        dp[1]=1;
        return solve(n);
    }
};