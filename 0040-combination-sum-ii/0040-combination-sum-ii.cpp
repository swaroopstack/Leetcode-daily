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
        for(int i=idx;i<candidates.size();i++){
            if(i>idx && candidates[i]==candidates[i-1]){
                continue;
            }
            if(candidates[i]>target){
                break;
            }
            temp.push_back(candidates[i]);
            solve(candidates,ans,target - candidates[i],i+1,temp);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int idx=0;
        sort(candidates.begin(),candidates.end());
        solve(candidates,ans,target,idx,temp);
        return ans;
    }
};