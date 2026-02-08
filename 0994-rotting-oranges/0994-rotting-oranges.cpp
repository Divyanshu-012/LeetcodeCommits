class Solution {
public:
    
  int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size();
  int n = grid[0].size();

  int cnt = 0;
  int cntFresh = 0;
  int ans = 0;

  queue<pair<pair<int,int>,int>>q;


  for(int i = 0; i<m ;i++){
    for(int j = 0; j<n ; j++){
      if(grid[i][j] == 2){
        q.push({{i,j},0});
        
      }
      
      if(grid[i][j] == 1) cntFresh++;
    }
  }

  while(!q.empty()){
    int row = q.front().first.first;
    int col = q.front().first.second;
    int time = q.front().second;
    q.pop();
    ans = max(time,ans);

    int delr[4] = {-1,1,0,0};
    int delc[4] = {0,0,-1,1};

    for(int i = 0; i<4;i++){
      int nrow = row+delr[i];
      int ncol = col + delc[i];

      if(nrow >=0 && nrow < m && ncol >=0 && ncol < n  && grid[nrow][ncol] ==1){
        q.push({{nrow,ncol},time+1});
        grid[nrow][ncol] = 2;
        cnt++;
      }
    }
  }
  if(cnt != cntFresh)return -1;
  return ans;

   
        
    }
};
