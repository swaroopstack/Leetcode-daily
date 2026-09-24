class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<pair<int,int>> directions{{-1,0},{1,0},{0,-1},{0,1}};
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                }
                if(mat[i][j] == 1) {
                    mat[i][j] = INT_MAX;
                }
            }
        }
        while(!q.empty()){
            int cr=q.front().first;
            int cc=q.front().second;
            q.pop();
            for(auto &it:directions){
                int nr=cr+it.first;
                int nc=cc+it.second;
                if(nr<0 || nr>=n || nc<0 || nc>=m){
                    continue;
                }
                if(mat[nr][nc]==INT_MAX){
                    mat[nr][nc]=mat[cr][cc]+1;
                    q.push({nr,nc});
                }
            }
        }
        return mat;
    }
};