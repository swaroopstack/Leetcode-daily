class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        int ans=0;
        for(int i : st){
            int x=i;
            if(st.find(x-1)==st.end()){
                int count=0;
                while(st.find(x)!=st.end()){
                    count++;
                    x++;
                }
                ans=max(ans,count);
            }
        }
        return ans;
    }
};