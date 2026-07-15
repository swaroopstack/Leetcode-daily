class Solution {
public:
    bool isPerfectSquare(int num) {
        long long i=1;
        while(true){
            long long x=i*i;
            if(x==num){
                return true;
            }
            else if(x>num){
                break;
            }
            else{
                i++;
            }
        }
        return false;
    }
};