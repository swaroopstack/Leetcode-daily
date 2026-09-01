class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        priority_queue<
            pair<int, string>,
            vector<pair<int, string>>,
            decltype([](const pair<int, string>& a, const pair<int, string>& b) {
                if (a.first != b.first)
                    return a.first < b.first;   // higher frequency first

                return a.second > b.second;     // lexicographically smaller first
            })
        > pq;
        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
        }
        for(auto &it : mp){
            pq.push({it.second,it.first});
        }
        vector<string> ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};