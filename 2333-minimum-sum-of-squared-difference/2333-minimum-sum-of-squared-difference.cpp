
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;

        vector<long long> diff(n);
        long long total = 0;
        long long high = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            total += diff[i];
            high = max(high, diff[i]);
        }

        if (k >= total) return 0;

        long long low = 0;

        while (low < high) {
            long long mid = low + (high - low) / 2;
            long long need = 0;

            for (long long x : diff) {
                if (x > mid) need += x - mid;
            }

            if (need <= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        long long level = low;
        long long used = 0;
        long long ans = 0;
        long long count = 0;

        for (long long x : diff) {
            if (x > level) {
                used += x - level;
                count++;
                ans += level * level;
            } else {
                ans += x * x;
            }
        }

        long long remaining = k - used;
        ans -= remaining * (2 * level - 1);

        return ans;
    }
};
