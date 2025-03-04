class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int p) {
        vector<int>ans;
        int n = nums.size();
        for(int i = 0; i< n;i++){
            if(nums[i] < p){
                ans.push_back(nums[i]);
            }
        }

        for(int i = 0; i< n;i++){
            if(nums[i] == p){
                ans.push_back(nums[i]);
            }
        }

        for(int i = 0; i< n;i++){
            if(nums[i] > p){
                ans.push_back(nums[i]);
            }
        }

        return ans;
        
    }
};