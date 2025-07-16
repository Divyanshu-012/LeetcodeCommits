class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int cntO =0;
        int cntE = 0;
        int cnt =1;
        int CNT=2;
        int n = nums.size();
        if(n < 2)return n;
        for(int i = 1 ; i<n;i++){
            if((nums[i] % 2) != (nums[i-1]%2)){
                cnt++;
            }
            
        }
        for(int i = 0 ; i<n;i++){
            if((nums[i] % 2) == 1){
                cntO++;
            }
            
        }
        for(int i = 0 ; i<n;i++){
            if((nums[i] % 2) == 0){
                cntE++;
            }
            
        }
        CNT= max(max(cntO,cntE),cnt);
        
        return CNT;
    }
};