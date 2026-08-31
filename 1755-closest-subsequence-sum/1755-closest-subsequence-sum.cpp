class Solution {
public:
    void solve(vector<int>& nums, int i, int sum, vector<int>& sums, int sz) {
        if (i == sz) {
            sums.push_back(sum);
            return;
        }
        solve(nums, i + 1, sum, sums, sz);
        solve(nums, i + 1, sum + nums[i], sums, sz);
    }
    int minAbsDifference(vector<int>& nums, int goal) {
        int sz = nums.size();
        vector<int> leftsum;
        vector<int> rightsum;
        solve(nums, 0, 0, leftsum, sz / 2);
        solve(nums, sz / 2, 0, rightsum, sz);
        int ans = INT_MAX;
        sort(rightsum.begin(), rightsum.end());
        for (int i = 0; i < leftsum.size(); i++) {
            
            int need = goal - leftsum[i];
            auto it = lower_bound(rightsum.begin(), rightsum.end(), need);

            if (it != rightsum.end()) {
                ans = min(ans, abs(leftsum[i] + *it - goal));
            }

            if (it != rightsum.begin()) {
                --it;
                ans = min(ans, abs(leftsum[i] + *it - goal));
            }
        }
        return ans;
    }
};