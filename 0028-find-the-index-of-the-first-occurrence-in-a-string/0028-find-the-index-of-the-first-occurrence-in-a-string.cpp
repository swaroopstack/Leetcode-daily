class Solution {
public:
    void kmp(string needle,vector<int>& lps){
        int len=0;
        int i=1;
        while(i<needle.size()){
            if(needle[i]==needle[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len!=0){
                    len=lps[len-1];
                }
                else{
                    i++;
                }
            }
        }
    }

    int strStr(string haystack, string needle) {
        int m=needle.size();
        int n=haystack.size();
        vector<int> lps(m,0);
        kmp(needle,lps);
        int i=0,j=0;
        while(i<n && j<m){
            if(haystack[i]==needle[j]){
                i++;
                j++;
            }
            else{
                if(j!=0){
                    j=lps[j-1];
                }
                else{
                    i++;
                }
            }
        }
        if(j==m) return abs(j-i);
        return -1;
    }
};