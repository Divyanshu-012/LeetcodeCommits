class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n, -1);

        
        int right = 2 * k + 1;
        if (right > n) return ans;

        long long windowSum = 0;

     
        for (int i = 0; i < right; i++) {
            windowSum += nums[i];
        }

        
        ans[k] = windowSum / right;

        
        for (int i = right; i < n; i++) {
            windowSum += nums[i];           
            windowSum -= nums[i - right]; 
            ans[i - k] = windowSum / right;
        }

        return ans;
    }
};
