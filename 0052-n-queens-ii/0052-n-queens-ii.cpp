class Solution {
public:
    int ans=0;
    bool valid(vector<string> &grid,int row, int col){
        for(int i=row-1;i>=0;i--){
            if(grid[i][col]=='Q'){
                return false;
            }
        }

        for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
            if(grid[i][j]=='Q'){
                return false;
            }
        }

        for(int i=row-1,j=col+1;i>=0 && j>=0;i--,j++){
            if(grid[i][j]=='Q'){
                return false;
            }
        }
        return true;
    }
    void solve(vector<string> &grid,int rows, int n){
        if(rows>=n){
            ans++;
        }
        for(int col=0;col<n;col++){
            if(valid(grid,rows,col)){
                grid[rows][col]='Q';
                solve(grid,rows+1,n);
                grid[rows][col]='.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<string> grid(n,string(n,'.'));
        solve(grid,0,n);
        return ans;
    }
};