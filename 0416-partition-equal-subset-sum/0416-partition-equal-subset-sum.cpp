class Solution {
public:
    bool solve(int i,vector<int>& nums,int target,vector<vector<int>> &dp){
        if(target==0){
            return true;
        }
        if(i==nums.size() || target<0){
            return false;
        }
        if(dp[i][target]!=-1){
            return dp[i][target];
        }
        bool take=solve(i+1,nums,target-nums[i],dp);
        bool skip=solve(i+1,nums,target,dp);
        return dp[i][target]=take || skip;
    }
    bool canPartition(vector<int>& nums) {
        int total=0;
        for(int x: nums){
            total+=x;
        }
        if(total%2!=0){
            return false;
        }
        int target=total/2;
        vector<vector<int>> dp(nums.size(),vector<int>(target + 1, -1));
        return solve(0,nums,target,dp);
    }
};