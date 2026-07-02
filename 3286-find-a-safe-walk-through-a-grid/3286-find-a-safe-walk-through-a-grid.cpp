class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        int m = grid.size();
        int n = grid[0].size();

        // dist[i][j] = minimum damage needed to reach (i,j)
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > pq;

        dist[0][0] = grid[0][0];
        pq.push({dist[0][0], 0, 0});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while(!pq.empty())
        {
            auto [damage, r, c] = pq.top();
            pq.pop();

            // Ignore outdated entries
            if(damage > dist[r][c])
                continue;

            for(int k = 0; k < 4; k++)
            {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                int newDamage = damage + grid[nr][nc];

                if(newDamage < dist[nr][nc])
                {
                    dist[nr][nc] = newDamage;
                    pq.push({newDamage, nr, nc});
                }
            }
        }

        return dist[m-1][n-1] < health;
    }
};