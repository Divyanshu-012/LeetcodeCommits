class Solution {
public:

    void bfs(int i, int j, vector<vector<int>> &image, int initialColor, vector<vector<int>> &vis, int color){
        queue<pair<int, int>> q;
        vis[i][j] = 1;
        q.push({i, j});
        int n = image.size();
        int m = image[0].size();

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            
            image[row][col] = color;

            
            for(int k = 0; k < 4; k++){
                int nrow = row + delrow[k];
                int ncol = col + delcol[k];
                
                
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && image[nrow][ncol] == initialColor){
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Get the initial color of the starting pixel
        int initialColor = image[sr][sc];

        
        if(initialColor != color) {
            bfs(sr, sc, image, initialColor, vis, color);
        }

        return image;
    }
};
