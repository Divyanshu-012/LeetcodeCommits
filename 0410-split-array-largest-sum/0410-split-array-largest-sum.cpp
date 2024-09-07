class Solution {
public:


    int findSum(vector<int> &nums, int mid){
        int sum = 0;
        int Lsum = 1;
        for(int i = 0; i<nums.size(); i++){
            if(sum + nums[i] <= mid){
                sum += nums[i];
            }
            else{
                Lsum++;
                sum = nums[i];
            }
        }
        return Lsum;
    }
    int splitArray(vector<int>& nums, int k) {
        
        int low = *max_element(nums.begin(),nums.end());
        int high  = accumulate(nums.begin(),nums.end(),0);

        while(low<= high ){
            int  mid = low + (high - low)/2;

            int Lsum = findSum(nums, mid);

            if(Lsum > k){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return low;
    }
};