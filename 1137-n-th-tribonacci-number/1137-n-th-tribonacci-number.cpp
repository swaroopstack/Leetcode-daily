class Solution {
public:
    vector<int> dp;
    int solve(int i){
        if(dp[i]!=-1){
            return dp[i];
        }
        return dp[i]=solve(i-1)+solve(i-2)+solve(i-3);
    }
    int tribonacci(int n) {
        dp.assign(n+1,-1);
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        if(n==2) return 1;
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;
        return solve(n);
    }
};