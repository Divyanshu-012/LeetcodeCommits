class Solution {
public:



    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        vector<int> ans;

        while (low <= high) {
            int mid = low + (high - low) / 2; 

            if (nums[mid] == target) {
                int  i = mid-1;
                while(i>=0 && nums[i]==target){
                        i--;
                    }
                    ans.push_back(i+1);
                int j=mid+1;
                while(j<n && nums[j]==target)j++;
                 ans.push_back(j-1);
                 break;

            }
            else if(nums[mid]>target)high=mid-1;
            else low=mid+1;
        
        }
        if(ans.size()==0){
            ans.push_back(-1);
            ans.push_back(-1);
        }
     
       
        return ans;
    }
};