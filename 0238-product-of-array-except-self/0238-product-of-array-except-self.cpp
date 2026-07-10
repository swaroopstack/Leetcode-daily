class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftpro(n, 1);
        vector<int> rightpro(n, 1);
        for (int i = 1; i < n; i++) {
            leftpro[i] = leftpro[i - 1] * nums[i-1];
        }
        for (int i = n - 2; i >= 0; i--) {
            rightpro[i] = rightpro[i + 1] * nums[i+1];
        }
        for(int i=0;i<n;i++){
            nums[i]=leftpro[i]*rightpro[i];
        }
        return nums;
    }
};