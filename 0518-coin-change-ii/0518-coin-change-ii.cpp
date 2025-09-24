class Solution {
public:
    int fn(int idx, vector<int>& coins, int sum, vector<vector<int>>& dp) {
        if (sum == 0) return 1;  
        if (idx == 0) {
            if ((sum %coins[0] )== 0 ) return 1;
            return 0;
        }
        if (idx < 0) return 0;  
        if (dp[idx][sum] != -1) return dp[idx][sum];  

        int notTake = fn(idx - 1, coins, sum, dp); 
        int take = 0;
        if (coins[idx] <= sum) {
            take = fn(idx, coins, sum - coins[idx], dp);  
        }

        return dp[idx][sum] = (take + notTake);  
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));  
        return fn(n - 1, coins, amount, dp);
    }
};