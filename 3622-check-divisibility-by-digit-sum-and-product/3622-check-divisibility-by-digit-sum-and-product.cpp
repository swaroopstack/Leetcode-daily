class Solution {
public:
    bool checkDivisibility(int n) {
        long long sum=0;
        long long pro=1;
        int org=n;
        while(n){
            int dig=n%10;
            sum+=dig;
            pro*=dig;
            n/=10;
        }
        sum+=pro;
        return org%sum==0;
    }
};