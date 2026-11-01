class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<int> left(n,0);
        vector<int> right(n,0);
        left[0]=nums[0];
        right[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            left[i]=left[i-1]+nums[i];
        }
        for(int i=n-2;i>=0;i--){
            right[i]=right[i+1]+nums[i];
        }
        //left ={2,5,10}
        //right={10,8,5}
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            int size=0;
            if(i>0){
                ans[i]+=(nums[i]*i)-left[i-1];
            }

            if(i<n-1){
                ans[i]+=right[i+1]-(nums[i]*(n-i-1));
            }
        }
        return ans;
    }
};