/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function (nums, target) {
   let low = 0,
        high = nums.length - 1;

    while (low <= high) {
        // Finding the mid using floor division
        let mid = low + Math.floor((high - low) / 2);

        // Target value is present at the middle of the
        // array
        if (nums[mid] == target) {
            return mid;
        }

        // low to mid is sorted
        if (nums[low] <= nums[mid]) {
            if (nums[low] <= target && target < nums[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        // mid to high is sorted
        else {
            if (nums[mid] < target && target <= nums[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    return -1;
};