class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()); 
        int n = nums.size();
        int cnt = 0;
        int i = 0;

        while (i < n) {
            int start = nums[i];
            cnt++;
            i++;

            while (i < n && nums[i] - start <= k) {
                i++;
            }
        }

        return cnt;
    }
};
