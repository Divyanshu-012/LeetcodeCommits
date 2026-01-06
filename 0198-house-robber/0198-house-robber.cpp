class Solution {
public:
    int solve(vector<int>& nums,int ind,vector<int>&dp){
        if(ind<1)return 0;
        if(ind==1)return nums[0];

        if(dp[ind-1] != -1) return dp[ind-1];
        int take = nums[ind-1]+solve(nums,ind-2,dp);

        int skip = 0+ solve(nums,ind-1,dp);

        return dp[ind-1] = max(take,skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return  solve(nums,n,dp);
       
        
    }
};