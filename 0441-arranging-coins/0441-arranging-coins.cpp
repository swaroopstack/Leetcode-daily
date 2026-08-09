class Solution {
public:
    int arrangeCoins(int n) {
        int low=0;
        int high=n;
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            int h=0;
            int coin=n;
            for(int i=1;i<=mid;i++){
                coin-=i;
                if(coin>=0){
                    h++;
                }
                else if(coin<0){
                    break;
                }
            }
            if(h==mid){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};