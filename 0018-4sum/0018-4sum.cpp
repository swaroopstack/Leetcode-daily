class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int l=j+1;
                int r=n-1;
                while(l<r){
                    long long sum=(long long)nums[i] + nums[j] + nums[l] + nums[r];
                    if(sum==target){
                        ans.push_back({nums[i] , nums[j] , nums[l] , nums[r]});
                        l++;
                        r--;
                    }
                    else if(sum<target){
                        l++;
                    }
                    else{
                        r--;
                    }
                }
            }
        }
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        return ans;
    }
};