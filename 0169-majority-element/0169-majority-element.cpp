class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int cnt = 1;
        int ans=-1 ;
        int n = nums.size();
        for(int i = 1;i<n;i++){
            if(nums[i]==nums[i-1]){
                cnt++;
            }
            else{
                
                cnt = 1;
            }
            ans = max(cnt,ans);

            if(ans > n/2){
                return nums[i];
            } 

        }

         
        return nums[0];
        
        
    }
};