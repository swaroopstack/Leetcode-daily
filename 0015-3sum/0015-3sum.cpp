class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            int l=i+1;
            int r=n-1;
            while(l<r){
                int sum=nums[i]+nums[l]+nums[r];
                if(sum==0){
                    ans.push_back({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                }
                else if(sum<0){
                    l++;
                }
                else{
                    r--;
                }
            }
        }
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        return ans;
    }
};

// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         vector<vector<int>> ans;
//         int n=nums.size();
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 for(int k=j+1;k<n;k++){
//                     if(i==j|| j==k || k==i){
//                         continue;
//                     }
//                     if(nums[i]+nums[j]+nums[k]==0){
//                         ans.push_back({nums[i],nums[j],nums[k]});
//                     }
//                 }
//             }
//         }
//         for(auto &v : ans) {
//             sort(v.begin(), v.end());
//         }
//         sort(ans.begin(),ans.end());
//         ans.erase(unique(ans.begin(), ans.end()), ans.end());
//         return ans;
//     }
// };