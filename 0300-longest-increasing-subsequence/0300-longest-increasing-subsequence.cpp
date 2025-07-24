class Solution {
public:
    int fn(vector<int>& nums, int idx, int p, vector<vector<int>>& dp) {
        int n = nums.size();
        if (idx >= n) return 0;

        if (dp[idx][p + 1] != -1) return dp[idx][p + 1];

        int take = 0;
        if (p == -1 || nums[idx] > nums[p]) {
            take = 1 + fn(nums, idx + 1, idx, dp);
        }
        int skip = fn(nums, idx + 1, p, dp);

        return dp[idx][p + 1] = max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return fn(nums, 0, -1, dp);
    }
};
