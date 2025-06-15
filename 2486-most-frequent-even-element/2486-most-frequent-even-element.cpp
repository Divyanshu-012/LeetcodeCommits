class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int , int> freq;
        for(int i = 0, n = nums.size(); i < n; ++i){
            if(nums[i] % 2 == 0) ++freq[nums[i]];
        }
        int maxi = -1, mfreq = 0;
        for(const auto& [key , cnt] : freq){
            if(cnt > mfreq){
                maxi = key;
                mfreq = cnt;
            }
            else if(cnt == mfreq) maxi = min(maxi , key);
        }
        return maxi;
    }
};