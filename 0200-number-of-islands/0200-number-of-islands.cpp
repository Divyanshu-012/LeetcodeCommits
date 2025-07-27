class Solution {
public:
    int delrow[4] = {1,-1,0,0};
    int delcol[4] = {0,0,1,-1};
    void dfs(int row, int col , vector<vector<char>>& grid,vector<vector<int>>&vis ){
        int m = grid.size();
        int n = grid[0].size();

        vis[row][col] = true;

        for(int k = 0; k<4;k++){
            int nrow = row + delrow[k];
            int ncol = col + delcol[k];

            if( nrow >=0 && nrow < m && ncol >= 0 && ncol<n && !vis[nrow][ncol] && grid[nrow][ncol] != '0'){
                dfs(nrow,ncol,grid,vis);
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>vis(m,vector<int>(n,false));
        int cnt = 0;
        for(int i = 0 ; i<m;i++){
            for(int j = 0; j< n;j++){
                if(grid[i][j] != '0' && !vis[i][j]){
                    cnt++;
                    dfs(i,j,grid,vis);
                }
            }
        }
        return cnt;
    }
};