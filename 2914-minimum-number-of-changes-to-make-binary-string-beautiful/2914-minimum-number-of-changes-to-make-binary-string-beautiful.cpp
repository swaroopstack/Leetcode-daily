class Solution {
public:
    int minChanges(string s) {
        int ans=0;
        int n=s.size();
        for(int i=0;i<n;i+=2){
            if(i+1<n && s[i]!=s[i+1]){
                ans++;
            }
        }
        return ans;
    }
};