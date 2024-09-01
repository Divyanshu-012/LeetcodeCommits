class Solution {
private:
    bool check(vector<int>& nums, int divisor, int threshold) {
        int sum = 0;
        for(auto&num : nums){
            sum +=(num + divisor - 1) / divisor; //to divide num by divisor and round up the result.
            if (sum > threshold) return false; // Early exit if sum exceeds threshold
        }
        return true;
    }
public:
    int smallestDivisor(std::vector<int>& nums, int threshold) {
        int left = 1;
        int right = *max_element(nums.begin(), nums.end());
        while(left <= right){
            int mid = left + (right - left) / 2;
            if (check(nums, mid, threshold)){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return left;
    }
};