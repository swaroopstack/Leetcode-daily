class Solution {
public:
    int maxProduct(int n) {
        long long pro=0;
        int max1=INT_MIN;
        int max2=INT_MIN;
        string s=to_string(n);
        sort(s.begin(),s.end());
        int len=s.size();
        pro=(s[len-1]-'0')*(s[len-2]-'0');
        return pro;
    }
};