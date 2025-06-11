class Solution {
public: 
    int fn(int ind , vector<int>&prices,int buy,int n,vector<vector<int>>&dp){
        if(ind >= n)return 0;

        if(dp[ind][buy] != -1) return dp[ind][buy];
        int profit= 0;
        if(buy){
            profit = max(-prices[ind] + fn(ind+1,prices,0,n,dp),
                    0 + fn(ind+1,prices,1,n,dp));
        }else{
            profit = max(prices[ind]+fn(ind+2,prices,1,n,dp),
                    fn(ind+1,prices,0,n,dp));
        }

        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return fn(0,prices,1,n,dp);

    }
};