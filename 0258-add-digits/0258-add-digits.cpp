class Solution {
public:
    int solve(int num){
        if(num<=0){
            return num;
        }
        return num%10+(num/10);
    }
    int addDigits(int num) {
        int ans=solve(num);
        while(ans>=10){
            ans=solve(ans);
        }
        return ans;
    }
};