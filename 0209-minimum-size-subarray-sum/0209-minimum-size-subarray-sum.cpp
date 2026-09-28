class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=nums.size()+1;
        int l=0;
        int r=0;
        int sum=0;
        while(r<nums.size()){
            sum+=nums[r];
            while(sum>=target){
                ans=min(ans,r-l+1);
                sum-=nums[l];
                l++;
            }
            r++;
        }
        if(ans>nums.size()){
            return 0;
        }
        return ans;
    }
};