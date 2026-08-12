class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int ans=0;
        int i=0;
        int j=0;
        while(j<nums.size()){
            if(mp[nums[j]]<k){
                mp[nums[j]]++;
                j++;
                ans=max(ans,j-i);
            }
            else{
                mp[nums[i]]--;
                i++;
            }
        }
        return ans;
    }
};