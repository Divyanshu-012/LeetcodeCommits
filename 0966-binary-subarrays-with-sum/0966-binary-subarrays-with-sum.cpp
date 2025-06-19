class Solution {
public:  
    int fn(vector<int>& nums, int goal) {
        int l = 0, r = 0, n = nums.size();
        int cnt = 0, sum = 0;
        if(goal<0) return 0;
        while (r < n) {
            sum += nums[r];

            
                while (  sum > goal) {
                sum -= nums[l];
                l++;
                }
        

            cnt += (r - l + 1);
            r++;
        }

        return cnt;
    }

  
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return fn(nums, goal) - fn(nums, goal - 1);
    }
};
