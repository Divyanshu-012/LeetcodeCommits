class Solution {
public:
    int atMost(vector<int>& nums, int goal) {
        int l = 0, r = 0, n = nums.size();
        int cnt = 0, sum = 0;

        while (r < n) {
            sum += nums[r]%2;

            while (l <= r && sum > goal) {
                sum -= nums[l]%2;
                l++;
            }

            cnt += (r - l + 1);
            r++;
        }

        return cnt;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};
