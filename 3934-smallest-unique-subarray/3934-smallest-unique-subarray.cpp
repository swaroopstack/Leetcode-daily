class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        long long mod1 = 1000000007;
        long long mod2 = 1000000009;
        long long base = 100001;

        vector<long long> p1(n + 1, 1), p2(n + 1, 1);
        vector<long long> h1(n + 1, 0), h2(n + 1, 0);

        for(int i = 0; i < n; i++) {
            h1[i + 1] = (h1[i] * base + nums[i]) % mod1;
            h2[i + 1] = (h2[i] * base + nums[i]) % mod2;

            p1[i + 1] = p1[i] * base % mod1;
            p2[i + 1] = p2[i] * base % mod2;
        }

        auto check = [&](int k) {
            unordered_map<long long, int> mp;

            for(int i = 0; i + k <= n; i++) {
                long long a = (h1[i + k] - h1[i] * p1[k] % mod1 + mod1) % mod1;
                long long b = (h2[i + k] - h2[i] * p2[k] % mod2 + mod2) % mod2;

                long long key = a * mod2 + b;
                mp[key]++;
            }

            for(auto it : mp) {
                if(it.second == 1)
                    return true;
            }

            return false;
        };

        int l = 1, r = n, ans = n;

        while(l <= r) {
            int mid = l + (r - l) / 2;

            if(check(mid)) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        return ans;
    }
};