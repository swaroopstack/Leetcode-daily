class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc=1;
        int dec=1;
        int r=1;
        int n=nums.size();
        int ans=1;
        while(r<n){
            if(nums[r]>nums[r-1]){
                inc++;
            }
            else{
                inc=1;
            }
            r++;
            ans=max(ans,inc);
        }
        r=1;
        while(r<n){
            if(nums[r]<nums[r-1]){
                dec++;
            }
            else{
                dec=1;
            }
            r++;
            ans=max(ans,dec);
        }
        return ans;
    }
};