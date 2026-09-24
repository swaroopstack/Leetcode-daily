class Solution {
public:
    vector<pair<int,int>> directions{{-1,0},{1,0},{0,-1},{0,1}};
    int numEnclaves(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n=grid.size();
        int m=grid[0].size();
        for(int i = 0; i < n; i++) {
            if(grid[i][0] == 1) {
                q.push({i, 0});
                grid[i][0] = 0;
            }

            if(grid[i][m-1] == 1) {
                q.push({i, m-1});
                grid[i][m-1] = 0;
            }
        }

        for(int j = 0; j < m; j++) {
            if(grid[0][j] == 1) {
                q.push({0, j});
                grid[0][j] = 0;
            }

            if(grid[n-1][j] == 1) {
                q.push({n-1, j});
                grid[n-1][j] = 0;
            }
        }
        int ans=0;
        while(!q.empty()){
            int sz=q.size();
            int cr=q.front().first;
            int cc=q.front().second;
            q.pop();

            for(auto &direction : directions) {
                int nr = cr + direction.first;
                int nc = cc + direction.second;

                if(nr < 0 || nr >= n || nc < 0 || nc >= m)
                    continue;

                if(grid[nr][nc] == 1) {
                    grid[nr][nc] = 0;
                    q.push({nr, nc});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    ans++;
                }
            }
        }
        return ans;
    }
};