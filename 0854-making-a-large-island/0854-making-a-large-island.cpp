class Solution {
public:
    int delrow[4] = {-1,1,0,0};
    int delcol[4] = {0,0,-1,1};

    int dfs(int row, int col, int uniq_id,vector<vector<int>>& grid) {
        int n = grid.size();
    grid[row][col]=uniq_id;
    int cnt = 1;
       for(int k = 0; k<4;k++){
        int nrow= row+delrow[k];
        int ncol = col+delcol[k];

        if(nrow < n&& nrow >= 0&& ncol <n && ncol >=0 && grid[nrow][ncol] == 1){
            cnt+= dfs(nrow,ncol,uniq_id,grid);
        }
       }
       return cnt;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int uniq_id = 2;
        unordered_map<int,int>mp;
        int size = 0;

        for(int i = 0;i<n;i++){
            for(int j = 0; j<n;j++){
                if(grid[i][j]== 1){
                    int cnt = dfs(i,j,uniq_id,grid);
                    size = max(size,cnt);
                    mp[uniq_id] = cnt;
                    uniq_id++;
                }
            }
        }

        for(int i = 0; i<n;i++){
            for(int j = 0 ;j<n;j++){
                if(grid[i][j] == 0){
                    unordered_set<int>uniqueId;
                    for(int k = 0;k<4;k++){
                        int i_ = i+delrow[k];
                        int j_ = j+delcol[k];
                        if(i_ >= 0 && i_ <n && j_ >=0 && j_ <n && grid[i_][j_] !=0){
                            uniqueId.insert(grid[i_][j_]);
                        }
                    }

                    int overallSize = 1;
                    for(auto it: uniqueId){
                        overallSize += mp[it];
                    }
                    size = max(size,overallSize);
                }
            }
        }
        return size;


    }
};
