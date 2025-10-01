class Solution {
public:
    int MOD = 10;
    int triangularSum(vector<int>& nums) {
        int n  = nums.size();

        while(n>1){
            int i = 0;
            while(i<n-1){
                nums[i] = (nums[i]+nums[i+1]) % MOD;
                i++;
            }
            n--;

        }
        return nums[0];
    }
};