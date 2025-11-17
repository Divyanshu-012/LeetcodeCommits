class Solution {
public:
    vector<vector<int>> memo;
    vector<int> nums1, nums2;
    int n;

    int solve(int i, int swapped) {
        if (i == n) return 0;
        if (memo[i][swapped] != -1) return memo[i][swapped];

        int prev1 = (i == 0) ? -1 : (swapped ? nums2[i - 1] : nums1[i - 1]);
        int prev2 = (i == 0) ? -1 : (swapped ? nums1[i - 1] : nums2[i - 1]);

        int res = INT_MAX;

        // No swap at i
        if (nums1[i] > prev1 && nums2[i] > prev2)
            res = min(res, solve(i + 1, 0));

        // Swap at i
        if (nums2[i] > prev1 && nums1[i] > prev2)
            res = min(res, 1 + solve(i + 1, 1));

        return memo[i][swapped] = res;
    }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        n = nums1.size();
        memo = vector<vector<int>>(n, vector<int>(2, -1));
        return solve(0, 0);
    }
};