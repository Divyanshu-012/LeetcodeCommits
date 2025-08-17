class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int res = 0;
        for(int i = 1, n = nums.size(); i < n; ++i){
            if(nums[res] < nums[i]) ++res;
        }
        return res;
    }
};