class Solution {
public:
    int fn(int ind, int buy, vector<int>& prices, int k, vector<vector<vector<int>>>& dp) {
        if (ind == prices.size() || k == 0) return 0;

        if (dp[ind][buy][k] != -1) return dp[ind][buy][k];

        int profit = 0;
        if (buy) {
            profit = max(-prices[ind] + fn(ind+1, 0, prices, k, dp),
                         fn(ind+1, 1, prices, k, dp));
        } else {
            profit = max(prices[ind] + fn(ind+1, 1, prices, k-1, dp),
                         fn(ind+1, 0, prices, k, dp));
        }

        return dp[ind][buy][k] = profit;
    }

    int maxProfit(int k,vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return fn(0, 1, prices, k, dp);
    }
};
