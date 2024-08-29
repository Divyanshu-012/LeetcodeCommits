class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return true;
            }
            if(nums[mid]==nums[low]&&nums[mid]==nums[high]){
                low++;
                high--;
                continue;
            }

            // Check if the left half is sorted
            if (nums[low] <=nums[mid]) {
                // Check if the target is in the left half
                if (nums[low] <= target && target <= nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            
            // Otherwise, the right half must be sorted
            else {
                // Check if the target is in the right half
                if (nums[mid] <= target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return false; // Target not found
    }
};
