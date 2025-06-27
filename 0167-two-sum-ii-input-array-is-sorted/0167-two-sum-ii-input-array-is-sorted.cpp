class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int t) {
        int n = nums.size();
      
        for(int i = 0 ; i<n-1; i++){
           
            int s=i+1, e=n-1;
            
            while(s <= e){
                int mid = (s+e)/2;
                if(nums[mid] == t - nums[i])return {i+1,mid+1};
                if(nums[mid] > t - nums[i] ) e = mid-1;
                else s = mid+1;
                
            }
            
        }
        
        
        return {};
    }
};