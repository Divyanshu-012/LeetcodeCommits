class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;

        if(nums[low]<nums[high]){
            return nums[low];
        }
        
        

        while(low<high){
            int mid = low + (high - low) / 2;
            

            if( mid>0 && nums[mid]<nums[mid-1]  ){
                return nums[mid];
            }

            if(nums[mid]<nums[high]){
                high= mid-1;
            }

            else{
                low= mid+1;
            }
        }

        return nums[low];

        
    }
};