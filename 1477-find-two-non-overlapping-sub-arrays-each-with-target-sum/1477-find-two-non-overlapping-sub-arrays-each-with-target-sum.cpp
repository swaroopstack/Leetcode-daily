class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        int i=0;
        int j=0;
        int currsum=0;
        vector<int> minBestLenTillIdx(n,INT_MAX);
        int bestMinLen= INT_MAX;
        int ans=INT_MAX;
        while(j<n){
            currsum+=arr[j];
            while(i<=j && currsum>target){
                currsum-=arr[i++];
            }
            if(currsum==target){
                int len=j-i+1;
                if(i>0 && minBestLenTillIdx[i-1]!=INT_MAX){
                    ans=min(ans,len+minBestLenTillIdx[i-1]);
                }
                bestMinLen=min(bestMinLen,len);
            }
            minBestLenTillIdx[j]=bestMinLen;
            j++;
        }
        return ans==INT_MAX ? -1 : ans;
    }
};