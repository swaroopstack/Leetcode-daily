class Solution {
public:
    int digsum(int n){
        int sum=0;
        while(n){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        vector<int> sorted(nums);

        auto customsort=[&](int a,int b){
            int dsum1=digsum(a);
            int dsum2=digsum(b);
            if(dsum1!=dsum2){      //if digit sum is not equal then sort based on sum else on values
                return dsum1<dsum2;
            }
            return a<b;
        };

        sort(sorted.begin(),sorted.end(),customsort);
        unordered_map<int,int> mp;   // to map original value to its index
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=i;
        }
        int swaps=0;
        for(int i=0;i<nums.size();i++){
            int ex=sorted[i];   // the number expected after sort
            int val=nums[i];  // curr value
            if(ex!=val){
                // if both are not equal the move the val to expected mapped idx
                int idx=mp[ex];   // expected index
                swap(nums[i],nums[idx]);
                swaps++; 
                mp[ex]=i;
                mp[val]=idx;   //updating their mapped index after swapping
            }
        }
        return swaps;
    }
};