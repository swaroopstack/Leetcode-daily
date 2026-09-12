class Solution {
public:
    struct State {
        long long score;
        vector<int> indices;
    };

    // Returns true if a is better than b
    bool better(const State& a, const State& b) {
        if (a.score != b.score)
            return a.score > b.score;

        return a.indices < b.indices;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // Store {l, r, weight, original_index}
        vector<array<int, 4>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Sort by left endpoint
        sort(a.begin(), a.end(), [](const auto& x, const auto& y) {
            if (x[0] != y[0])
                return x[0] < y[0];

            if (x[1] != y[1])
                return x[1] < y[1];

            return x[3] < y[3];
        });

        // next[i] = first interval whose left > a[i].right
        vector<int> next(n);

        for (int i = 0; i < n; i++) {
            int lo = i + 1;
            int hi = n;

            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;

                if (a[mid][0] > a[i][1])
                    hi = mid;
                else
                    lo = mid + 1;
            }

            next[i] = lo;
        }

        /*
            dp[i][k]:
            Best answer considering intervals [i ... n-1]
            when we can still select at most k intervals.
        */
        vector<vector<State>> dp(
            n + 1,
            vector<State>(5)
        );

        // Base case:
        // If no intervals remain, score = 0 and indices = {}
        for (int k = 0; k <= 4; k++) {
            dp[n][k] = {0, {}};
        }

        for (int i = n - 1; i >= 0; i--) {

            // k = 0 => cannot select anything
            dp[i][0] = {0, {}};

            for (int k = 1; k <= 4; k++) {

                // Option 1: skip interval i
                State skip = dp[i + 1][k];

                // Option 2: take interval i
                State take = dp[next[i]][k - 1];

                take.score += a[i][2];
                take.indices.push_back(a[i][3]);

                // We need indices sorted for lexicographical comparison
                sort(take.indices.begin(), take.indices.end());

                if (better(take, skip))
                    dp[i][k] = take;
                else
                    dp[i][k] = skip;
            }
        }

        return dp[0][4].indices;
    }
};