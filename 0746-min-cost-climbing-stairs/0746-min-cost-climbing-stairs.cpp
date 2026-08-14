class Solution {
public:
    vector<int> dp;
    int solve(int i,vector<int>& cost){
        if(dp[i]!=-1){
            return dp[i];
        }
        return dp[i]=cost[i]+ min(solve(i-1,cost),solve(i-2,cost));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        dp.assign(n+1,-1);
        dp[0]=cost[0];
        dp[1]=cost[1];
        return min(solve(n-1,cost),solve(n-2,cost));
    }
};