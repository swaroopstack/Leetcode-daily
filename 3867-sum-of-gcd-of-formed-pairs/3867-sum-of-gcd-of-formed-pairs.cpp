class Solution {
public:
    long long gcd(long long a,long long b){
        if(b==0) return a;
        return gcd(b,a%b);
    }
    long long gcdSum(vector<int>& nums) {
        long long mx=INT_MIN;
        int n=nums.size();
        vector<int> prefixGcd(n);
        for(int i=0;i<n;i++){
            mx=max(mx,(long long)nums[i]);
            prefixGcd[i]=gcd(nums[i],mx);
        }
        int low=0;
        int high=prefixGcd.size()-1;
        sort(prefixGcd.begin(),prefixGcd.end());
        long long sum=0;
        while(low<high){
            sum+=gcd(prefixGcd[low],prefixGcd[high]);
            low++;
            high--;
        }
        return sum;
    }
};