class Solution {
public:
    int fn(vector<int>& coins, int amt,int idx,vector<vector<int>>&dp){
        int n = coins.size();
        if(idx == n)return 1e9;
        if(idx == n-1 ){
            if((amt % coins[n-1])==0){
                return amt/coins[n-1];
            }
            return 1e9;
        }
        if(amt == 0){
            return 0;
        }

        if(dp[idx][amt] != -1)return dp[idx][amt];
        int take = 1e9;
        if(coins[idx] <= amt){
            take = 1+fn(coins,amt-coins[idx],idx,dp);
        }

        int notTake = 0+fn(coins,amt,idx+1,dp);

        return dp[idx][amt]=min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amt) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amt+1,-1));
        int res = fn(coins,amt,0,dp);
        if(res == 1e9) return -1;
        return res;
        
    }
};