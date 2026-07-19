class Solution {
public:
    vector<pair<int,int>> dirs{{-1,0},{1,0},{0,-1},{0,1}};
    void dfs(int currentrow,int currentcol,vector<vector<int>>& image, int color,int s){
        
        image[currentrow][currentcol]=color;
        int rows=image.size();
        int cols=image[0].size();
        for(auto dir:dirs){
            int nextrow=currentrow + dir.first;
            int nextcol=currentcol + dir.second;
            if(nextrow >= 0 && nextrow < rows && nextcol >= 0 && nextcol < cols && 
                image[nextrow][nextcol]==s){
                    dfs(nextrow,nextcol,image,color,s);
                }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int rows=image.size();
        int cols=image[0].size();
        int source=image[sr][sc];
        if (source == color)
            return image;
        dfs(sr,sc,image,color,source);
        return image;
    }
};