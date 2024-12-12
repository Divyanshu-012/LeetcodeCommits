class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        // Initialize the answer matrix with a large value (infinity)
        vector<vector<int>> ans(n, vector<int>(m, INT_MAX));
        queue<pair<int, int>> q; // Queue to process BFS
        
        // Push all '0' cells into the queue and initialize their distance as 0
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        // BFS to update distances
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            for (int k = 0; k < 4; k++) {
                int nrow = r + delrow[k];
                int ncol = c + delcol[k];
                
                // Check boundaries and if the current distance can be minimized
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                    if (ans[nrow][ncol] > ans[r][c] + 1) {
                        ans[nrow][ncol] = ans[r][c] + 1;
                        q.push({nrow, ncol}); // Push this cell for further processing
                    }
                }
            }
        }
        
        return ans;
    }
};
