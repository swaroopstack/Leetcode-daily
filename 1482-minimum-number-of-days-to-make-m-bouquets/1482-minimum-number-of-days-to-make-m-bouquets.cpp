class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = 1;
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int bouquets = 0;
            int flowers = 0;
            for (int i = 0; i < bloomDay.size(); i++) {
                if (bloomDay[i] <= mid) {
                    flowers++; // consecutive bloomed flower
                } else {
                    bouquets += flowers / k; // make bouquets from this segment
                    flowers = 0;             // adjacency breaks here
                }
            }
            bouquets += flowers / k;
            if(bouquets>=m){
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