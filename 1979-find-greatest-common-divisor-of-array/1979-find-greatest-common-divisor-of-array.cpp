class Solution {
public:
    int gcd(int a,int b){
        if(b==0) return a;
        return gcd(b,a%b);
    }
    int findGCD(vector<int>& nums) {
        int mini=INT_MAX, maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<mini) mini = nums[i];
            if(nums[i]>maxi) maxi=nums[i];
        }
        return gcd(mini,maxi);
    }
};