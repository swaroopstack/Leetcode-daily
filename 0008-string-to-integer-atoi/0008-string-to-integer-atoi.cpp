class Solution {
public:
    int maxim = INT_MAX;
    int minim = INT_MIN;
    int solve(string& s, int i, long long num, int sign) {
        if (i >= s.size() || !isdigit(s[i])) {
            return (int)(sign * num);
        }
        num = num * 10 + (s[i]-'0');
        if(sign*num<=minim) return minim;
        if(sign*num>=maxim) return maxim;
        return solve(s,i+1,num,sign);
    }

    int myAtoi(string s) {
        int i = 0;
        while (i < s.size() && s[i] == ' ') {
            i++;
        }
        int sign = 1;
        if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        return solve(s, i, 0, sign);
    }
};