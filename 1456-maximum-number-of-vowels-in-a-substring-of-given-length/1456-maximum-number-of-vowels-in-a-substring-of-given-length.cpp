class Solution {
public:
    bool isvowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }   
    int maxVowels(string s, int k) {
        int vow=0;
        for(int i=0;i<k;i++){
            if(isvowel(s[i])){
                vow++;
            }
        }
        int maxvow=vow;
        for(int i=k;i<s.size();i++){
            bool first=isvowel(s[i-k]);
            if(first){
                vow--;
            }
            bool now=isvowel(s[i]);
            if(now){
                vow++;
            }
            maxvow=max(maxvow,vow);
        }
        return maxvow;
    }

};