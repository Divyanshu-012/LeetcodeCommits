class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> output;
        vector<int> currentSeq;
        vector<int> nums(9);
        iota(nums.begin(), nums.end(), 1);

        combination(nums, 0, n, k, currentSeq, output);


        return output;
    }

private:
    bool combination(vector<int>& nums, int pos, int target, int length, vector<int>& currentSeq, vector<vector<int>>& output) {
        if(currentSeq.size() > length) {
            return false;
        }
        if(target == 0 && currentSeq.size() == length) {
            output.push_back(currentSeq);
            return true;
        }
        else if(target < 0) {
            return false;
        }

        for(int i = pos; i < nums.size(); ++i) {
            currentSeq.push_back(nums[i]);

            auto result = combination(nums, i+1, target-nums[i], length, currentSeq, output);

            currentSeq.pop_back();

            if(!result) {
                return true;
            }
        }
        return true;
    }

};