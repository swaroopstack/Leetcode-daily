class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());
        int low = 1;
        int high = position[n - 1] - position[0];
        int ans = INT_MIN;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int count = 1;          // first ball
            int last = position[0]; // first ball placed here
            bool fit=false;
            for (int i = 1; i < position.size(); i++) {
                if (position[i] - last >= mid) {
                    // We can place another ball
                    count++;
                    last = position[i];
                }
                if (count >= m){
                    fit=true;
                }
            }
            if(fit){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};