class Solution {
public:
    vector<vector<int>>dir = {{1,0},{0,1},{-1,0},{0,-1}};
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>ans;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        if(grid[start[0]][start[1]]==0) return ans;
        pq.push({0,grid[start[0]][start[1]],start[0],start[1]});
        grid[start[0]][start[1]] = 0;
        while(!pq.empty() and ans.size()<k){
            auto curr = pq.top();
            pq.pop();
            int dist = curr[0];
            int price = curr[1];
            int x = curr[2];
            int y = curr[3];
            if(price>=pricing[0] and price<=pricing[1]) ans.push_back({x,y});
            for(int i=0;i<4;i++){
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                if(nx<0 or ny<0 or nx>=n or ny>=m) continue;
                if(grid[nx][ny]==0) continue;
                pq.push({dist+1,grid[nx][ny],nx,ny});
                grid[nx][ny] = 0;
            }
        }
        return ans;
    }
};