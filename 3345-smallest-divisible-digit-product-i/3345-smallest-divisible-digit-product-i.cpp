class Solution {
public:
    int smallestNumber(int n, int t) {
        while(true){
            int temp=n;
            int pro=1;
            while(temp){
                int dig=temp%10;
                pro*=dig;
                temp/=10;
            }
            if(pro%t==0){
                return n;
            }
            else{
                n++;
            }
        }
        return 0;
    }
};