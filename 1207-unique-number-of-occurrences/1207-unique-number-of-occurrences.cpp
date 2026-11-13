class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_set<int> occ;
        unordered_map<int,int> mp;
        for(int x:arr){
            mp[x]++;
        }
        for(auto &it:mp){
            occ.insert(it.second);
        }
        return mp.size()==occ.size();
    }
};