class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        unordered_set<int> s;
        for(int i=0;i<target.size();i++){
            s.insert(target[i]);
        }
        int len=target.size();
        for(int i=1;i<=n;i++){
            if(len==0){
                break;
            }
            if(s.count(i)){
                len--;
                ans.push_back("Push");
            }
            else{
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        }
        return ans;
    }
};