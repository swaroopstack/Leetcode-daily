class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int rows=heights.size();
        int cols=heights[0].size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,greater<tuple<int, int, int>>> pq;
        vector<vector<int>> dist(rows, vector<int>(cols, 1e9));
        dist[0][0] = 0;
        pq.push({0,0,0});
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        while(!pq.empty()){
            auto [effort,r,c]=pq.top();
            pq.pop();
            if(r==rows-1 && c==cols-1) return effort;

            if(effort>dist[r][c]) continue;

            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                    int diff = abs(heights[r][c] - heights[nr][nc]);

                    int neweffort = max(effort, diff);

                    if(neweffort < dist[nr][nc]) {
                        dist[nr][nc] = neweffort;
                        pq.push({neweffort, nr, nc});
                    }
                }
            }
        }
        return 0;

    }
};