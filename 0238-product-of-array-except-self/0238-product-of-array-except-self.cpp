class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        long long p = 1;
        int cnt = 0;
        int save ;
        for(int i = 0; i<n;i++){
            if(nums[i] == 0){
                cnt++;
                save = i;
            }
            p *= nums[i];
        }
        int d = 1;
        if(p == 0 && cnt == 1){
            
            for(int i = 0; i<n;i++){
            if(i == save)continue;
            d *= nums[i];
        }
        }
        vector<int>ans ;
        if(cnt == 0 || cnt > 1){
            for(int i = 0; i<n;i++){
                int curr= nums[i];
                long long  val;
                if(curr != 0){
                    val = p/curr;
                }else{
                    val = 0;
                }
                
                ans.push_back(val);
            }
        }else{
            for(int i = 0; i<n;i++){
                int curr= nums[i];
                long long  val;
                if(curr != 0){
                    val = p/curr;
                }else{
                    val = d;
                }
                
                ans.push_back(val);
            }
        }
        

        return ans;
    }
};