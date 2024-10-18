class Solution {
public:

    int  countSubsets(int idx, int currOr, vector<int>& nums,int maxOr){
        if(idx == nums.size()){
            return (currOr == maxOr) ? 1 : 0;
        }

        int takeCount = countSubsets(idx+1, currOr | nums[idx], nums, maxOr);

        int notTake = countSubsets(idx+1, currOr, nums, maxOr);

        return takeCount + notTake;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for(int  &num : nums){
            maxOr |= num;
        }

        int currOr = 0;
        return countSubsets(0,currOr, nums, maxOr);
    }
};