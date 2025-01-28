class Solution {
public:
    int bfs(int row , int col , vector<vector<int>>&vis, vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();

        vis[row][col] = 1;
        queue<pair<int,pair<int,int>>>q;

        q.push({grid[row][col],{row,col}});
        int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        int maxcount = 0;
        int currentFish = 0;
        while(!q.empty()){
            int fishcnt = q.front().first;
            int row_ = q.front().second.first;
            int col_ = q.front().second.second;
            q.pop();

            currentFish += grid[row_][col_];
            maxcount = max(maxcount, currentFish);

            for(int k = 0 ; k< 4; k++){
                int nrow = row_ + dir[k][0];
                int ncol = col_ + dir[k][1];

                if(nrow >=0 && nrow < n && ncol >=0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] >0){
                    q.push({fishcnt + grid[nrow][ncol],{nrow,ncol}});
                    vis[nrow][ncol] = 1;
                    // maxcount = max(fishcnt + grid[nrow][ncol],maxcount);

                }
            }
            
        }
        
        return maxcount;

    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));
        int overallMax = 0;

        for(int i = 0;i < n ; i++){
            for(int j = 0 ; j< m ;j++){
                if(!vis[i][j] && grid[i][j] >0){
                    overallMax = max(overallMax, bfs(i, j, vis, grid));
                }
            }
        }
        return overallMax;
        
    }
};