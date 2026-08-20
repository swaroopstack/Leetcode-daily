class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int high=0;
        for(int i=0;i<nums.size();i++){
            high+=nums[i];
        }
        int low=*max_element(nums.begin(),nums.end());
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            int d=1;
            int cap=mid;
            for(int i=0;i<nums.size();i++){
                if(nums[i]<=cap){
                    cap-=nums[i];
                }
                else{
                    cap=mid;
                    cap-=nums[i];
                    d++; 
                }
            }
            if(d<=k){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};