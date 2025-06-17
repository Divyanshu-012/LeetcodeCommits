class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int r = 0; int l = 0;
        int  t = k;
        int cnt = 0;int cntz=0;
        while (r < n) {
            if (nums[r] == 0) cntz++;

            while (cntz > k) {
                if (nums[l] == 0) cntz--;
                l++;
            }

            cnt = max(cnt, r - l + 1);
            r++;
        }

        return cnt;
    }
};