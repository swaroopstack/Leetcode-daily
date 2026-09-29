class Solution {
public:
    int m,n;
    vector<vector<vector<int>>> dp;

    bool solve(vector<vector<char>>& grid,int i,int j,int count){
        count+=(grid[i][j]=='(')? 1:-1;
        if(count<0){
            return false;
        }
        if(i==m-1 && j==n-1){
            return count==0;
        }
        if(dp[i][j][count]!=-1){
            return dp[i][j][count];
        }
        bool ans=false;
        if(i+1<m){
            if(solve(grid,i+1,j,count)){
                ans=true;
            }
        }
        if(j+1<n){
            if(solve(grid,i,j+1,count)){
                ans=true;
            }
        }
        return dp[i][j][count]=ans;
    }

    bool hasValidPath(vector<vector<char>>& grid){
        m=grid.size();
        n=grid[0].size();

        if((m+n-1)%2==1){
            return false;
        }
        if(grid[0][0]==')' || grid[m-1][n-1]=='('){
            return false;
        }

        dp.assign(m,vector<vector<int>>(n,vector<int>(m+n+1,-1)));

        return solve(grid,0,0,0);
    }
};