class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int> mp;
        for(char c:s){
            mp[c]++;
        }
        int mini=101;
        int maxi=0;
        for(auto it :mp){
            if(it.second%2==0){
                mini=min(it.second,mini);
            }
            else{
                maxi=max(it.second,maxi);
            }
        }
        return maxi-mini;
    }
};