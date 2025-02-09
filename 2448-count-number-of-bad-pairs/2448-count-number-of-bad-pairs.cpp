class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long cnt = 0;
        unordered_map<int, int> mp;
        
        for (int i = 0; i < n; ++i) {
            int key = nums[i] - i;
            if (mp.find(key) != mp.end()) {
                cnt += (i - mp[key]);
            } else {
                cnt += i;
            }
            mp[key]++;
        }
        
        return cnt;
        
    }
};