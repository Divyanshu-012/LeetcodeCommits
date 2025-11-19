class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
       int total = 0; 
       int prev = 0 ;
        int n = nums.size();
       for(int i = 0; i<n; i++){
        total += nums[i];
        prev += i * nums[i];
       }
       int i = n-1;
       int ans = prev;
       while(i >= 1){
        int curr = prev + (total - nums[i]) - ((n-1) * nums[i]);
        ans = max(ans,curr);
        prev = curr;
        i--;
       }

       return ans;
    }
};