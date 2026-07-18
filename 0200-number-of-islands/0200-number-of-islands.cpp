class Solution {
public:
    vector<pair<int, int>> directions = {
        {-1, 0},   // Up
        {1, 0},    // Down
        {0, -1},   // Left
        {0, 1}     // Right
    };

    void dfs(int currentRow, int currentCol, vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        grid[currentRow][currentCol] = '0'; // marking this visited
        for (auto direction : directions) {
            int nextRow = currentRow + direction.first;
            int nextCol = currentCol + direction.second;

            if (nextRow >= 0 && nextRow < rows && nextCol >= 0 && nextCol < cols &&
                grid[nextRow][nextCol] == '1') {

                dfs(nextRow, nextCol, grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int count=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]=='1'){
                    count++;
                    dfs(i,j,grid);
                }
            }
        }
        return count;
    }
};