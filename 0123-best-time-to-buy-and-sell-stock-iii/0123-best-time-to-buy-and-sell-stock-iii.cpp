class Solution {
public:
    int fn(int ind, vector<int>& prices, int k, vector<vector<int>>& dp) {
        if (ind == prices.size() || k == 0) return 0;

        if (dp[ind][k] != -1) return dp[ind][k];

        int profit = 0;
        if (k % 2 == 0) {
            profit = max(-prices[ind] + fn(ind+1, prices, k-1, dp),
                         fn(ind+1, prices, k, dp));
        } else {
            profit = max(prices[ind] + fn(ind+1, prices, k-1, dp),
                         fn(ind+1, prices, k, dp));
        }

        return dp[ind][k] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(5,  -1));
        return fn(0, prices, 4, dp);
    }
};
