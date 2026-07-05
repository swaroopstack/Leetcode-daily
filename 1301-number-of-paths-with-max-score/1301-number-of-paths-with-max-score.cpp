class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        const int MOD = 1e9 + 7;

        vector<vector<int>> dp(n, vector<int>(n, -1));
        vector<vector<int>> ways(n, vector<int>(n, 0));

        dp[0][0] = 0;
        ways[0][0] = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'X' || (i == 0 && j == 0))
                    continue;

                int best = -1;
                int cnt = 0;

                vector<pair<int, int>> prev = {
                    {i - 1, j},
                    {i, j - 1},
                    {i - 1, j - 1}
                };

                for (auto [x, y] : prev) {
                    if (x < 0 || y < 0 || dp[x][y] == -1)
                        continue;

                    if (dp[x][y] > best) {
                        best = dp[x][y];
                        cnt = ways[x][y];
                    } else if (dp[x][y] == best) {
                        cnt = (cnt + ways[x][y]) % MOD;
                    }
                }

                if (best == -1)
                    continue;

                dp[i][j] = best;
                ways[i][j] = cnt;

                if (board[i][j] >= '1' && board[i][j] <= '9')
                    dp[i][j] += board[i][j] - '0';
            }
        }

        if (dp[n - 1][n - 1] == -1)
            return {0, 0};

        return {dp[n - 1][n - 1], ways[n - 1][n - 1]};
    }
};