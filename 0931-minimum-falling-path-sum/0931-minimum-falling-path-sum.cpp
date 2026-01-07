class Solution {
public:
    int fn(int i , int j , vector<vector<int>>&dp,vector<vector<int>>& matrix){
      
      int n = matrix[0].size();
      if (j < 0 || j >= n) return 1e9; 
      if (i == 0) return matrix[0][j];
      
      if(dp[i][j] != -1) return dp[i][j];

      int up = matrix[i][j] + fn(i-1,j,dp,matrix);
      int uL = matrix[i][j] + fn(i-1,j-1,dp,matrix);
      int uR = matrix[i][j] + fn(i-1,j+1,dp,matrix);

      return dp[i][j] = min({up,uL,uR});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
      int m = matrix.size();
      int n = matrix[0].size();
      vector<vector<int>>dp(m,vector<int>(n,-1));
      int mini = 1e9;
        for (int j = 0; j < n; j++) {
            mini = min(mini, fn(m - 1, j, dp, matrix));
        }
      return mini;  
        
    }
};