class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> leftm(n,0);
        vector<int> rightm(n,0);
        int left=0,right=0;
        for(int i=0;i<n;i++){
            left=max(left,height[i]);
            leftm[i]=left;
        }
        for(int i=n-1;i>=0;i--){
            right=max(right,height[i]);
            rightm[i]=right;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=min(leftm[i],rightm[i])-height[i];
        }
        return ans;
    }
};