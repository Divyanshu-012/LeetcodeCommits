class Solution {
public:
    int fn(int n,vector<int>&dp){
        if(n<0)return 0;
        if(n==0)  {
            return 1;
        }
        if(dp[n]!= -1)return dp[n];
        int take2 = 0;
        if(n > 1){
            take2 = fn(n-2,dp) ;
        }

        // take 1 step 
        int take1 = fn(n-1,dp);
        
        

    return dp[n] = take1+take2;


    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return fn(n,dp);
    }
};