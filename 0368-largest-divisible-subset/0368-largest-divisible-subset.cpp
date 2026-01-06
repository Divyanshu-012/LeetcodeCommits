class Solution {
public:
    vector<vector<vector<int>>> dp;

    vector<int> fn(int idx, int prev, vector<int>& nums) {
        int n = nums.size();
        if (idx == n) return {};

        if (!dp[idx][prev + 1].empty())
            return dp[idx][prev + 1];

        // skip 
        vector<int> skip = fn(idx + 1, prev, nums);

        // take 
        vector<int> take;
        if (prev == -1 || nums[idx] % nums[prev] == 0) {
            take = fn(idx + 1, idx, nums);
            take.insert(take.begin(), nums[idx]);
        }

        // Choose larger subset
        if (take.size() > skip.size())
            dp[idx][prev + 1] = take;
        else
            dp[idx][prev + 1] = skip;

        return dp[idx][prev + 1];
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());  
        int n = nums.size();
        dp = vector<vector<vector<int>>>(n, vector<vector<int>>(n + 1));

        return fn(0, -1, nums);
    }
};
