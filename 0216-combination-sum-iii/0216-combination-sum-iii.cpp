class Solution {
public:

    void combination(vector<int>& nums, int ind, int target, int length, vector<int>& ds, vector<vector<int>>& output) {
       
        if(target == 0 && ds.size() == length) {
            output.push_back(ds);
            return;
        }
        if(target < 0 || ds.size() > length) {
            return;
        }
        for(int i = ind; i < nums.size(); i++) {
            if(nums[i] <= target) {
                ds.push_back(nums[i]);
                combination(nums, i + 1, target - nums[i], length , ds, output);
                ds.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> output;
        vector<int> ds;
        vector<int> nums(9);
        iota(nums.begin(), nums.end(), 1);

        combination(nums, 0, n, k, ds, output);

        return output;
    }
};
