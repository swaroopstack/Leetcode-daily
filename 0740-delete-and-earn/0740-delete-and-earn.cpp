class Solution {
public:
    unordered_map<int,int> mp;
    vector<int> dp;
    int solve(int i, int n,vector<int>& nums){
        if(i>=n) return 0;
        if (dp[i] != -1) return dp[i];

        int take= (nums[i]*mp[nums[i]]);
        int j=i;

        //skip same value
        while(j<n && nums[j]==nums[i]){
            j++;
        }

        //skip nums[i]+1 value
        while(j<n && nums[j]==nums[i]+1){
            j++;
        }

        take+=solve(j,n,nums);
        int skip=solve(i+1,n,nums);
        return dp[i] =max(take,skip);
    }

    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        dp.assign(nums.size(),-1);
        return solve(0,nums.size(),nums);
    }
};