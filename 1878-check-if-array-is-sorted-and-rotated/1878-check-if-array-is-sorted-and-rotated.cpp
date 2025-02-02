class Solution {
public:
    bool check(vector<int>& nums) {
        int size = nums.size();

        
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        
        for (int i = 0; i < size; ++i) {
            bool isMatch = true;
            for (int index = 0; index < size; ++index) {
                if (nums[(i + index) % size] !=
                    sortedNums[index]) {
                    isMatch = false;
                    break;
                }
            }
            if (isMatch) {
                return true;
            }
        }

        return false;
    }
};