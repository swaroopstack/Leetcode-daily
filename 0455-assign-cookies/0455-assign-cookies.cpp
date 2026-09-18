class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int gend=g.size()-1;
        int send=s.size()-1;
        while(send>=0 && gend>=0){
            if(g[gend]<=s[send]){
                ans++;
                gend--;
                send--;
            }
            else{
                gend--;
            }
        }

        return ans;
    }
};