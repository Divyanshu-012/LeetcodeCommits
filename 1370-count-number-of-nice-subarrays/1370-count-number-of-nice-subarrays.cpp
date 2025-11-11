class Solution {
public:
    // int fn(vector<int>& nums, int goal) {
    //     int l = 0, r = 0, n = nums.size();
    //     int cnt = 0, sum = 0;

    //     while (r < n) {
    //         if(nums[r]%2 != 0) sum ++;


    //         while ( sum > goal) {
    //             if(nums[l] %2 != 0)sum --;
    //             l++;
    //         }

    //         cnt += (r - l + 1);
    //         r++;
    //     }

    //     return cnt;
    // }

    int numberOfSubarrays(vector<int>& nums, int k) {
    int l = 0, r = 0, n = nums.size();
    int cnt = 0;   // number of odd numbers in current window
    int ans = 0;

    while (r < n) {
        if (nums[r] % 2 != 0) cnt++;  // increment count of odd numbers

        // Shrink from left if we have more than k odd numbers
        while (cnt > k) {
            if (nums[l] % 2 != 0) cnt--;
            l++;
        }

        // Now, if cnt == k, count how many subarrays ending at r are valid
        if (cnt == k) {
            int temp = l;
            // Count how many even numbers we can skip from the left
            while (temp < n && nums[temp] % 2 == 0)
                temp++;

            // All these even prefixes form valid subarrays
            ans += (temp - l + 1);
        }

        r++;
    }

    return ans;
}

};