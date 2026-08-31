class Solution {
public:
    int solve(vector<int>& nums, int k){
        int odd=0;
        int l=0;
        int ans=0;
        for(int r=0; r<nums.size(); r++){
            if(nums[r]%2!=0){
                odd++;
                while(odd>k){
                    if(nums[l]%2!=0){
                        odd--;
                    }
                    l++;
                }
            }
            ans+=r-l+1;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};