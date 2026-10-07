class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        string ans;
        for(char c: t){
            mp[c]++;
        }
        int l=0;
        int r=0;
        int len=INT_MAX;
        int count=t.size();
        int start=0;
        while(r<s.size()){
            if(mp.contains(s[r])){
                if(mp[s[r]]>0){
                    count--;
                }
                mp[s[r]]--;
            }
            while(count==0){
                if(r-l+1 < len){
                    start=l;
                    len=r-l+1;
                }
                if(mp.contains(s[l])){
                    mp[s[l]]++;
                    if(mp[s[l]]>0){
                        count++;
                    }
                }
                l++;
            }
            
            r++;
        }
        if(len!=INT_MAX){
            ans=s.substr(start,len);
        }
        return ans;
    }
};