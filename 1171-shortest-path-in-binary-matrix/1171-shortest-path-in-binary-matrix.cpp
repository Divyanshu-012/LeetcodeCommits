class Solution {
public:
    int bfs(int row,int col, vector<vector<int>>& grid, vector<vector<int>> &vis){
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, pair<int, int>>> q;
        q.push({1, {row, col}}); // 0th index element 
        vis[row][col] = 1;

        int dir[8][2] = {{1, 1}, {0, 1}, {-1, 1}, {0, -1}, {-1, 0}, {1, -1}, {1, 0}, {-1, -1}};

        while(!q.empty()){
            int dist = q.front().first;
            int row_ = q.front().second.first;
            int col_ = q.front().second.second;
            q.pop();

            if (row_ == n - 1 && col_ == m - 1) {
                return dist;
            }


            for(int i = 0; i < 8;i++){
                int nrow = row_ + dir[i][0];
                int ncol = col_ + dir[i][1];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 0 && vis[nrow][ncol] == 0){
                q.push({dist + 1, {nrow, ncol}});
                vis[nrow][ncol] = 1;
                
                }

            }

        }

        return -1;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n  = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        int row = 0;
        int col = 0;
        if (grid[0][0] != 0 || grid[n - 1][m - 1] != 0) {
            return -1;
        }
        
        return bfs(row,col,grid,vis);
        

        
        
    }
};