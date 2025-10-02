class Solution {
public:
    int fn(int idx,vector<int>& nums,vector<int>&dp){
        int n = nums.size();
        if(idx >= n-1)return 0;

        if(dp[idx] != -1)return dp[idx];
        int mini = INT_MAX;

        for(int i = 1; i<= nums[idx];i++){
            int next = fn(idx + i, nums, dp);
            if (next != INT_MAX) {
                mini = min(mini, 1 + next); 
            }
        }
        return dp[idx] = mini;
    }
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
       return fn(0,nums,dp);
    }
};