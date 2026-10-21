class Solution {
public:
    int minOperations(string s) {
        string sorted=s;
        sort(sorted.begin(),sorted.end());
        if(sorted==s){
            return 0;
        }
        int n=s.size();
        if(n==2){
            return -1;
        }
        char small = *min_element(s.begin(), s.end());
        char large = *max_element(s.begin(), s.end());

        if (s[0] == large && s[n - 1] == small) {
            if (count(s.begin(), s.end(), large) == 1 && count(s.begin(), s.end(), small) == 1) {
                return 3;
            }
            return 2;
        }

        if (s[0] == small || s[n - 1] == large) {
            return 1;
        }
        return 2;
    }
};