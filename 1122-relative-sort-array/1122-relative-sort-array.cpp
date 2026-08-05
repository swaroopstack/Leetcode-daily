class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> mp;
        for(int i=0;i<arr1.size();i++){
            mp[arr1[i]]++;
        }
        vector<int> ans;
        for(int i=0;i<arr2.size();i++){
            if(mp.find(arr2[i])!=mp.end()){
                ans.insert(ans.end(), mp[arr2[i]], arr2[i]);
                mp.erase(arr2[i]);
            }
        }
        vector<int> nums;
        for(int i=0;i<arr1.size();i++){
            if(mp.find(arr1[i])!=mp.end()){
                nums.push_back(arr1[i]);
            }
        }
        sort(nums.begin(),nums.end());
        ans.insert(ans.end(), nums.begin(), nums.end());
        return ans;
    }
};