class Solution {
public:
    int maxArea(vector<int>& height) {
        int low=0;
        int high=height.size()-1;
        int ans=0;
        while(low<high){
            int width=abs(low-high);
            int h=min(height[low],height[high]);
            ans=max(ans,width*h);
            if(height[low]<height[high]){
                low++;
            }
            else{
                high--;
            }
        }
        return ans;
    }
};