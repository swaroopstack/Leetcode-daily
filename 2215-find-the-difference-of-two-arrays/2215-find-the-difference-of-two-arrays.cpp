class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st1(nums1.begin(), nums1.end());
        unordered_set<int> st2(nums2.begin(), nums2.end());
        vector<vector<int>> ans;
        vector<int> first;
        vector<int> second;
        for(auto it = st1.begin(); it != st1.end(); it++){
            if(!st2.count(*it)){
                first.push_back(*it);
            }
        }
        for(auto it=st2.begin();it!=st2.end();it++){
            if(!st1.count(*it)){
                second.push_back(*it);
            }
        }
        return {first,second};
    }
};