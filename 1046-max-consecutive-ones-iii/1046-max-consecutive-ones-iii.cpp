class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int r = 0; int l = 0;
        
        int cnt = 0;
        while (r < n) {
            if (nums[r] == 0) k--;

            while (k <0) {
                if (nums[l] == 0) k++;
                l++;
            }

            cnt = max(cnt, r - l + 1);
            r++;
        }

        return cnt;
    }
};