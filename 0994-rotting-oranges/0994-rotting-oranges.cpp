class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols= grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    fresh++;
                } else if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        if (fresh == 0)
            return 0;
        int minutes = 0;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int currentRow = q.front().first;
                int currentCol = q.front().second;
                q.pop();

                for (auto direction : directions) {

                    int nextRow = currentRow + direction.first;
                    int nextCol = currentCol + direction.second;

                    if (nextRow < 0 || nextRow >= rows || nextCol < 0 ||
                        nextCol >= cols)
                        continue;

                    if (grid[nextRow][nextCol] == 1) {

                        grid[nextRow][nextCol] = 2;
                        fresh--;
                        q.push({nextRow, nextCol});
                    }
                }
            }
            if(!q.empty()){
                minutes++;
            }
        }
        if(fresh==0){
            return minutes;
        }
        return -1;
    }
};