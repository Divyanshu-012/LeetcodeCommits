class Solution {
public:
    int fn(vector<int>& nums, int goal) {
        int l = 0, r = 0, n = nums.size();
        int cnt = 0, sum = 0;

        while (r < n) {
            if(nums[r]%2 != 0) sum ++;

// giviing wrong answer for the case [2,1,1], k = 1
            while ( sum > goal) {
                if(nums[l] %2 != 0)sum --;
                l++;
            }

            cnt += (r - l + 1);
            r++;
        }

        return cnt;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return fn(nums,k) - fn(nums,k-1);
    }
};