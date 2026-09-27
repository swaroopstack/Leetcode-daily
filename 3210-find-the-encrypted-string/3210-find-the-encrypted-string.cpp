class Solution {
public:
    string getEncryptedString(string s, int k) {
        string ans=s;
        for(int i=0;i<s.size();i++){
            int newidx=(i+k)%s.size();
            ans[i]=s[newidx];
        }
        return ans;
    }
};