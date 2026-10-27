class Solution {
public:
    vector<string> createGrid(int m, int n) {
        string s=".";
        for(int i=1;i<n;i++){
            s+='#';
        }
        vector<string> ans(m-1,s);
        s="";
        for(int i=0;i<n;i++){
            s+='.';
        }
        ans.push_back(s);
        return ans;
    }
};