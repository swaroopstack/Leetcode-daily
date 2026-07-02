class Solution {
public:
    int m, n;
    vector<vector<int>> g;
    vector<vector<bool>> visited;
    vector<vector<vector<int>>> dp;
    bool dfs(int i, int j, int health) {
        if (i < 0 || i >= m || j < 0 || j >= n)
            return false;

        if (g[i][j] == 1)
            health--;

        if (health <= 0)
            return false;

        if (i == m - 1 && j == n - 1)
            return true;

        if(dp[i][j][health] != -1)
            return dp[i][j][health];

        if (visited[i][j])
            return false;

        visited[i][j] = true;

        bool found = dfs(i + 1, j, health) || dfs(i - 1, j, health) ||
                     dfs(i, j + 1, health) || dfs(i, j - 1, health);

        visited[i][j] = false;
        dp[i][j][health] = found;
        return found;
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        g = grid;

        m = g.size();
        n = g[0].size();
        dp = vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(health + 1, -1)));
        visited.assign(m, vector<bool>(n, false));

        return dfs(0, 0, health);
    }
};