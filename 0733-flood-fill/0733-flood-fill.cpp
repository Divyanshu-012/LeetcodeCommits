class Solution {
public:
    int delrow[4] = {-1,0,0,1};
    int delcol[4] = {0,-1,1,0};

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>>vis(m,vector<int>(n,false));

        int rem = image[sr][sc];
        image[sr][sc] = color;
        
        queue<pair<int,int>>q;
        q.push({sr,sc});

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int k= 0;k<4;k++){
                int nrow = row+delrow[k];
                int ncol = col + delcol[k];

                if(nrow >= 0 && nrow < m &&  ncol >=0   && ncol < n && !vis[nrow][ncol] && image[nrow][ncol] == rem){
                    q.push({nrow,ncol});
                    image[nrow][ncol] = color;
                    vis[nrow][ncol] = true;
                }
            }
        }
        return image;
    }
};