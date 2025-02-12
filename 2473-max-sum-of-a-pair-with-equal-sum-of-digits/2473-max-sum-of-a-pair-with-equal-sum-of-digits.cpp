class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        int result = -1;

        int mp[82] = {};

        for(int i = 0 ; i< n ; i++){
            int sum = 0;
            int store = nums[i];
            while(store > 0){
                sum += store % 10; 
                store /= 10; 
            }
            if(mp[sum] > 0){
                result = max(result, mp[sum] + nums[i]);
            }
            mp[sum] = max(mp[sum], nums[i]);
            
        }

        return result;
    }
};