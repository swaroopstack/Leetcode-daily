class Solution {
public:
    long long maximumProduct(vector<int>& nums) {
        long long mx1 = LLONG_MIN, mx2 = LLONG_MIN, mx3 = LLONG_MIN;
        long long mn1 = LLONG_MAX, mn2 = LLONG_MAX;

        for (int x : nums) {
            // largest three
            if (x >= mx1) {
                mx3 = mx2;
                mx2 = mx1;
                mx1 = x;
            } else if (x >= mx2) {
                mx3 = mx2;
                mx2 = x;
            } else if (x > mx3) {
                mx3 = x;
            }

            // smallest two
            if (x <= mn1) {
                mn2 = mn1;
                mn1 = x;
            } else if (x < mn2) {
                mn2 = x;
            }
        }

        return max(mx1 * mx2 * mx3, mx1 * mn1 * mn2);
    }
};