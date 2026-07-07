class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n==0){
            return 0;
        }
        long long x=0;
        string s = to_string(n);
        for(int i=0;i<s.size();i++){
            if(s[i]!='0'){
                x=x*10+(s[i]-'0');
            }
        }
        long long sum=0;
        long long org=x;
        while(org){
            int digit=org%10;
            sum+=digit;
            org/=10;
        }
        return x*sum;
    }
};