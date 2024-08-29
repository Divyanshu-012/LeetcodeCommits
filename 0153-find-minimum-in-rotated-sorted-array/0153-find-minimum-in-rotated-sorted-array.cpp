class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        // If the array is not rotated (or has only one element)
        if (nums[low] < nums[high]) {
            return nums[low];
        }

        while (low < high) {
            int mid = low + (high - low) / 2;

            // Check if mid is the minimum element
            if (mid > 0 && nums[mid] < nums[mid - 1]) {
                return nums[mid];
            }

            // Determine which half to search
            if (nums[mid] > nums[high]) {
                low = mid + 1;  // Search the right half
            } else {
                high = mid;  // Search the left half (mid might be the minimum)
            }
        }

        // Low should point to the minimum element
        return nums[low];
    }
};
