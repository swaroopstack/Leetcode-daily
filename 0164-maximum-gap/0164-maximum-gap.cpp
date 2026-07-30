class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        if(n<2){
            return 0;
        }
        int ans=0;
        for(int i=0;i<n-1;i++){
            ans=max(ans,nums[i+1]-nums[i]);
        }
        return ans;
    }
};