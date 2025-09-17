class Solution {
public:
    int fn(int i , int j , vector<vector<int>>& a, vector<vector<int>>&dp){
      if(i == 0 && j == 0) return a[0][0];
      if(i<0 || j < 0) return 1e5;

      if(dp[i][j] != -1) return dp[i][j];

      int up = a[i][j] + fn(i-1,j,a,dp);
      int left = a[i][j] + fn(i,j-1,a,dp);

      return dp[i][j]= min(up,left);

    }
    int minPathSum(vector<vector<int>>& a) {
      
      int m = a.size();
      int n = a[0].size();
      vector<vector<int>>dp(m,vector<int>(n,-1));
      return fn(m-1,n-1,a,dp);

    }
};