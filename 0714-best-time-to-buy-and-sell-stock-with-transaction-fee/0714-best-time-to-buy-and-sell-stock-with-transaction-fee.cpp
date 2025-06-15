class Solution {
public: 
    int fn(int ind , vector<int>&prices,int buy,int n,vector<vector<int>>&dp,int fee){
        if(ind == n)return 0;

        if(dp[ind][buy] != -1) return dp[ind][buy];
        int profit= 0;
        if(buy){
            profit = max(-prices[ind] + fn(ind+1,prices,0,n,dp,fee),
                    0 + fn(ind+1,prices,1,n,dp,fee));
        }else{
            profit = max(prices[ind]-fee+fn(ind+1,prices,1,n,dp,fee),
                    fn(ind+1,prices,0,n,dp,fee));
        }

        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices,int fee) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return fn(0,prices,1,n,dp,fee);

    }
};