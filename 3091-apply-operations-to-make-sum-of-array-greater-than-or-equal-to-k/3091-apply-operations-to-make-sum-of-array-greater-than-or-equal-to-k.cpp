class Solution {
public:
    int minOperations(int k) {
        if(k==1){
            return 0;
        }
        int ans=INT_MAX;
        for(int i=1;i<=k;i++){
            int increment=i-1;
            int duplicate=(k+i-1)/i-1;
            ans=min(ans,increment+duplicate);
        }
        return ans;
    }
};