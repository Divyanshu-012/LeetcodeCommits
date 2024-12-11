class Solution {
private:
    void bfs(int row, int col, vector<vector<int>> & vis, vector<vector<int>> & grid){
        vis[row][col] = 1; 
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        q.push({row,col});
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            // traverse in the neighbours and mark them if its a island 
            for(int  k = 0; k <4; k++){
                    int nrow = row + drow[k];
                    int ncol = col + dcol[k];
                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 0 && !vis[nrow][ncol]){
                        vis[nrow][ncol] = 1;
                        q.push({nrow,ncol});
                    }
                
            }

        }
          
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        int cnt = 0;

        for(int row = 0; row< n; row++){
            for(int  col = 0; col < m; col++){
                if((row == 0 || col == 0 || row == n - 1 || col == m - 1) && 
                    grid[row][col] == 0 && !vis[row][col]){
                    
                    bfs(row, col , vis, grid);
                }
            }
        }

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (grid[row][col] == 0 && !vis[row][col]) {
                    cnt++;
                    bfs(row, col, vis, grid);
                }
            }
        }
        return cnt;
        
    }
};