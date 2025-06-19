class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        int l = 0, cnt = 0;
        int n = nums.size();

        for (int r = 0; r < n; r++) {
            if (nums[r] % 2 == 1) k--;

            while (k < 0) {
                if (nums[l] % 2 == 1) k++;
                l++;
            }

            cnt += (r - l + 1);
        }

        return cnt;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};
