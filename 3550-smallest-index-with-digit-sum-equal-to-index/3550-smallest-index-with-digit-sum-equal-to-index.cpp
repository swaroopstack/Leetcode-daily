class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int small=nums.size()+1;
        for(int i=0;i<nums.size();i++){
            int n=nums[i];
            int sum=0;
            while(n){
                sum+=n%10;
                n/=10;
            }
            if(sum==i){
                small=min(small,i);
            }
        }
        if(small>nums.size()){
            return -1;
        }
        return small;
    }
};