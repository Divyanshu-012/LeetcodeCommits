class Solution {
private:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid, int delrow[], int delcol[]) {
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        
        // Traverse all 4 possible directions
        for (int k = 0; k < 4; k++) {
            int nrow = row + delrow[k];
            int ncol = col + delcol[k];
            // Check boundary conditions and valid cell to visit
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
                !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
                dfs(nrow, ncol, vis, grid, delrow, delcol);
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        int delrow[] = {-1, 0, +1, 0}; // Direction vectors for row
        int delcol[] = {0, 1, 0, -1};  // Direction vectors for column
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Mark all land cells connected to the boundary
        for (int j = 0; j < m; j++) {
            // First row
            if (!vis[0][j] && grid[0][j] == 1) {
                dfs(0, j, vis, grid, delrow, delcol);
            }
            // Last row (only if n > 1 to avoid double-processing in n = 1 case)
            if (n > 1 && !vis[n - 1][j] && grid[n - 1][j] == 1) {
                dfs(n - 1, j, vis, grid, delrow, delcol);
            }
        }

        for (int i = 0; i < n; i++) {
            // First column
            if (!vis[i][0] && grid[i][0] == 1) {
                dfs(i, 0, vis, grid, delrow, delcol);
            }
            // Last column (only if m > 1 to avoid double-processing in m = 1 case)
            if (m > 1 && !vis[i][m - 1] && grid[i][m - 1] == 1) {
                dfs(i, m - 1, vis, grid, delrow, delcol);
            }
        }

        // Count remaining unvisited land cells
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
