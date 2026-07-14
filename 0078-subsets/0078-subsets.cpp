class Solution {
public:
    void solve(vector<int>& nums,vector<vector<int>>& ans, int idx,vector<int>& temp){
        if(idx>=nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[idx]);
        solve(nums,ans,idx+1,temp);
        temp.pop_back();
        solve(nums,ans,idx+1,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int idx=0;
        solve(nums,ans,idx,temp);
        return ans;
    }
};