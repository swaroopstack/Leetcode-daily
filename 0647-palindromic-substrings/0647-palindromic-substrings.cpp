class Solution {
public:
    int countSubstrings(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                bool palindrome=true;
                int low=i;
                int high=j;
                while(low<=high){
                    if(s[low]!=s[high]){
                        palindrome=false;
                        break;
                    }
                    low++;
                    high--;
                }
                if(palindrome){
                    ans++;
                }
            }
        }
        return ans;
    }
};