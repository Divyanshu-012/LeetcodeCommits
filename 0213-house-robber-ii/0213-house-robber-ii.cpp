class Solution {
public:
    long long int robLinear(vector<int>& nums) {
        int n = nums.size();
        long long int prev = nums[0];
        long long int prev2 = 0;
        
        for (int i = 1; i < n; i++) {
            long long int take = nums[i];
            if (i > 1) take += prev2;

            long long int notTake = prev;

            long long int curi = max(take, notTake);
            prev2 = prev;
            prev = curi;
        }
        
        return prev;
    }

    long long int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> arr1(nums.begin() + 1, nums.end()); // Exclude the first house
        vector<int> arr2(nums.begin(), nums.end() - 1); // Exclude the last house

        long long int result1 = robLinear(arr1);
        long long int result2 = robLinear(arr2);

        return max(result1, result2);
    }
};
