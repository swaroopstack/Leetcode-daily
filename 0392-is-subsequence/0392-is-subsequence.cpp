class Solution {
public:
    bool isSubsequence(string s, string t) {
        int last=0;
        for(char c: s){
            bool found=false;
            for(int i=last;i<t.size();i++){
                if(c==t[i]){
                    last=i+1;
                    found=true;
                    break;
                }
            }
            if(!found){
                return false;
            }
        }
        return true;
    }
};