class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,char>,vector<pair<int,char>>> pq;
        unordered_map<char,int> mp;
        for(int x: s){
            mp[x]++;
        }
        for(auto &it: mp){
            pq.push({it.second,it.first});
        }
        string ans="";
        while(!pq.empty()){
            int k=pq.top().first;
            while(k--){
                ans.push_back(pq.top().second);
            }
            pq.pop();
        }
        return ans;
    }
};