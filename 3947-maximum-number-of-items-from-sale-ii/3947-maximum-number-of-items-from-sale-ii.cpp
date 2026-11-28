class Solution {
public:
    long long maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> cnt(n + 1, 0);
        int minprice = INT_MAX;

        for (auto &x : items) {
            cnt[x[0]]++;
            minprice = min(minprice, x[1]);
        }

        vector<int> gain(n + 1, 0);

        // Count how many other item types each factor unlocks
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j += i) {
                gain[i] += cnt[j];
            }
            gain[i]--; // exclude the item itself
        }

        // Process boosted purchases in increasing price
        sort(items.begin(), items.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });

        long long ans = 0;

        for (auto &x : items) {
            int factor = x[0];
            int price = x[1];

            // A boosted purchase is worthwhile only below 2 * minprice
            if (price >= 2LL * minprice) break;

            int take = min(gain[factor], budget / price);

            ans += 2LL * take;
            budget -= take * price;
        }

        // Spend remaining budget on cheapest normal purchases
        ans += budget / minprice;

        return ans;
    }
};