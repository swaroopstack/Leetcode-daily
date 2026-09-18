class Solution {
public:
    int count=0;
    void countInversion(vector<int>& nums,int low,int mid,int high){
        int right=mid+1;
        for(int i=low;i<=mid;i++){
            while(right<=high && (1ll*nums[i])>(1ll*2*nums[right])){
                right++;
            }
            count+=(right-(mid+1));
        }
    }
    void mergesort(vector<int>& nums,int low,int high){
        if(low>=high){
            return;
        }
        int mid=low+(high-low)/2;
        mergesort(nums,low,mid);
        mergesort(nums,mid+1,high);
        countInversion(nums,low,mid,high);
        merge(nums,low,mid,high);
    }
    void merge(vector<int>& nums,int low,int mid,int high){
        vector<int> temp;
        int i=low;
        int j=mid+1;
        while(i<=mid && j<=high){
            if(nums[i]<=nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else{
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i <= mid) {
            temp.push_back(nums[i]);
            i++;
        }

        while(j <= high) {
            temp.push_back(nums[j]);
            j++;
        }
        for(int k=low;k<=high;k++) {
            nums[k]=temp[k-low];
        }
    }
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        mergesort(nums,0,n-1);
        return count;
    }
};