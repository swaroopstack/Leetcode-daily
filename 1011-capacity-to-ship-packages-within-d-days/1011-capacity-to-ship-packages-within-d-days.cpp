class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int high=0;
        for(int i=0;i<weights.size();i++){
            high+=weights[i];
        }
        int low=*max_element(weights.begin(),weights.end());
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            int d=1;
            int cap=mid;
            for(int i=0;i<weights.size();i++){
                if(weights[i]<=cap){
                    cap-=weights[i];
                }
                else{
                    cap=mid;
                    cap-=weights[i];
                    d++; 
                }
            }
            if(d<=days){
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