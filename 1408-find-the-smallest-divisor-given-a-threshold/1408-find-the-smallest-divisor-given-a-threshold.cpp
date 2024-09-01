class Solution {
public:

    int Max_Elm(vector<int>& nums){
        int Maxi = INT_MIN;
        for(int i = 0; i < nums.size();i++){
            Maxi = max(nums[i],Maxi);
        }
        return Maxi;
    }

    int calculateDivisor(vector<int>&nums, int mid){
        int sum = 0;
        for(int  i = 0; i< nums.size();i++){
            sum += ceil((double)nums[i]/mid);
        }
        return sum;

    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = Max_Elm(nums);

        while(low<=high){
            int mid = low + (high-low)/2 ;
            int  sum = calculateDivisor(nums, mid);
            if(sum <= threshold){
                high  = mid-1;
            }
            else{
                low= mid+1;
            }

        }
        return low;
        
    }
};





// class Solution {
// private:
    

    

//     bool check(vector<int>& nums, int divisor, int threshold) {
//         int low = 1;
//         int high = Max_Elm(nums);

//         while(low<=high){
//             int mid = low + (high-low)/2 ;
//             int  sum = calculateDivisor(nums, mid);
//             if(sum <= threshold){
//                 high  = mid-1;
//             }
//             else{
//                 low= mid+1;
//             }

//         }
//         return low;

        
    
//     }
// };