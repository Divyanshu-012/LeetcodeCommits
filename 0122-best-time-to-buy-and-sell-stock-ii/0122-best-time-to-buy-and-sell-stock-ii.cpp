class Solution {
public:
    int fn(vector<int>& prices,int buy,int ind,vector<vector<int>>&dp){
        int n = prices.size();
        if(ind ==n) return 0;
        
        int profit = 0;
        if(dp[ind][buy]!= -1)return dp[ind][buy];
        if(buy){
            profit += max(-prices[ind]+ fn(prices,0,ind+1,dp),
                        0+fn(prices,1,ind+1,dp));
        }
        else{
            profit += max(prices[ind]+ fn(prices,1,ind+1,dp),
                        0+fn(prices,0,ind+1,dp));
        }
        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return fn(prices,1,0,dp);
    }
};