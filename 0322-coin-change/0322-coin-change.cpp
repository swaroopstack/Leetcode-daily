class Solution {
public:
    int solve(vector<int>& coins, int i, int amount, vector<vector<int>>& dp) {

        if (amount == 0)
            return 0;

        if (amount < 0 || i == coins.size())
            return 1e9;

        if (dp[i][amount] != -1)
            return dp[i][amount];

        int take = solve(coins, i, amount - coins[i], dp);
        if (take != 1e9)
            take++;

        int skip = solve(coins, i + 1, amount, dp);

        return dp[i][amount] = min(take, skip);
    }

    int coinChange(vector<int>& coins, int amount) {

        vector<vector<int>> dp(coins.size(),vector<int>(amount + 1, -1));

        int ans = solve(coins, 0, amount, dp);

        if (ans == 1e9)
            return -1;

        return ans;
    }
};