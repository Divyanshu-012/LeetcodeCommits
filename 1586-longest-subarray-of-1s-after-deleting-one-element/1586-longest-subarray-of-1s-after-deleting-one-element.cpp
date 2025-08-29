class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int save = accumulate(nums.begin(),nums.end(),0);

        if(save  == nums.size() || save == nums.size()-1) return nums.size()-1;

        int i =0; int j= 0;
        int k =1;
        int cnt = 0;
        int maxCnt =0;
        while(j<nums.size()){
            if(nums[j] == 0){
                k--;

            }
            else{
                cnt++;
            }
            if(k<0){
                if(nums[i] == 0){
                    k++;
                } else{
                    cnt--;
                }
                i++;
            }
            maxCnt = max(maxCnt,cnt);

            j++;
        }
        return maxCnt;
    }
};