class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sr, sc;
        int cnt = 0;

        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                if (classroom[i][j] == 'L') {
                    id[i][j] = cnt++;
                }
            }
        }

        if (cnt == 0)
            return 0;

        int totalMask = (1 << cnt) - 1;

        // best[r][c][mask] = maximum energy with which
        // we have reached this state.
        vector<vector<vector<int>>> best(
            m,
            vector<vector<int>>(
                n,
                vector<int>(1 << cnt, -1)
            )
        );

        struct State {
            int r, c, mask, e;
        };

        queue<State> q;

        q.push({sr, sc, 0, energy});
        best[sr][sc][0] = energy;

        int dist = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                auto [r, c, mask, e] = q.front();
                q.pop();

                if (mask == totalMask)
                    return dist;

                for (int d = 0; d < 4; d++) {

                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n)
                        continue;

                    if (classroom[nr][nc] == 'X')
                        continue;

                    // Need 1 energy to make a move
                    if (e == 0)
                        continue;

                    int ne = e - 1;
                    int nmask = mask;

                    // Collect litter
                    if (classroom[nr][nc] == 'L') {
                        nmask |= (1 << id[nr][nc]);
                    }

                    // Reset
                    if (classroom[nr][nc] == 'R') {
                        ne = energy;
                    }

                    // If we have already reached this state
                    // with MORE energy, this state is useless.
                    if (best[nr][nc][nmask] >= ne)
                        continue;

                    best[nr][nc][nmask] = ne;

                    q.push({nr, nc, nmask, ne});
                }
            }

            dist++;
        }

        return -1;
    }
};
