class Solution {
public:
    void solve(vector<int>& candidates,vector<vector<int>>& ans,int target,int idx,vector<int>& temp){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(idx>=candidates.size() || target<0){
            return;
        }
        
        temp.push_back(candidates[idx]);
        target-=candidates[idx];
        solve(candidates,ans,target,idx,temp);
        target += candidates[idx];
        temp.pop_back();
        solve(candidates,ans,target,idx+1,temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int idx=0;
        solve(candidates,ans,target,idx,temp);
        return ans;
    }
};