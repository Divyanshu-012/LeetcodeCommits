class Solution {
public:
    int minSubArrayLen(int t, vector<int>& nums) {
        int l =0, r=0;int cnt =0 ; int ans =INT_MAX;
        int n = nums.size();int sum = 0;
        int ultimate = accumulate(nums.begin(),nums.end(),0);
        if(ultimate < t) return 0;
        while(r<n){
            sum+= nums[r];
            while(sum >= t){
                cnt = r-l+1;
                ans = min(ans,cnt);
                sum-= nums[l];
                l++;
            }
            
                r++;
            
            
        }

        
        return ans;
    }
};