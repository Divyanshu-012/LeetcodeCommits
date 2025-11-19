class Solution {
public:
    int func(int i, int j, vector<vector<int>>& dp) {
        // base case
        if (i>j) return 0;
        if (i==j) return 0;
        if (dp[i][j]!=-1) {
            return dp[i][j];
        }
        // recursive case
        int ans=1e9;
        for (int k=i;k<j;k++) {
            ans = min(ans, k+max(func(i,k-1,dp),func(k+1,j,dp)));
        }
        return dp[i][j]=ans;
        
    }
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int> (n+1,-1));
        return func(1,n,dp);
    }
};