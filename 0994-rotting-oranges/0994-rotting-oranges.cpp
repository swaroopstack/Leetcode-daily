class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        queue<pair<int,int>> q;
        int fresh=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        if(fresh==0) return 0;
        int time=0;
        vector<pair<int,int>> directions={{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int cr=q.front().first;
                int cc=q.front().second;
                q.pop();
                for(auto dir:directions){
                    int nr=cr+dir.first;
                    int nc=cc+dir.second;
                    if(nr>=rows || nr<0 || nc>=cols || nc<0){
                        continue;
                    }
                    if(grid[nr][nc]==1){
                        fresh--;
                        grid[nr][nc]=2;
                        q.push({nr,nc});
                    }
                }
            }
            if(!q.empty()){
                time++;
            }
        }
        return fresh==0? time : -1;
    }
};