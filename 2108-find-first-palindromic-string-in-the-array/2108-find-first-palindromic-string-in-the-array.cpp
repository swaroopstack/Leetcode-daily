class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        string ans;
        for(string s:words){
            int low=0;
            int high=s.size()-1;
            bool pal=true;
            while(low<high){
                if(s[low]!=s[high]){
                    pal=false;
                    break;
                }
                low++;
                high--;
            }
            if(pal){
                ans=s;
                break;
            }
        }
        return ans;
    }
};