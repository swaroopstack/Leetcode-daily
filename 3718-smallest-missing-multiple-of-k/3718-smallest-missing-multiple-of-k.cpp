class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        int ans;
        int i=1;
        while(true){
            int x=k*i;
            if(!st.count(x)){
                ans=x;
                break;
            }
            i++;
        }
        return ans;
    }
};