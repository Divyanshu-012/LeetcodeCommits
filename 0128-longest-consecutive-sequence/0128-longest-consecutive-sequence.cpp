class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
       sort(nums.begin(),nums.end());
       unordered_set<int>st;
        int cnt=1;
        int ans = 1;
         int n = nums.size();
         if(n ==0) return 0;
       for(int i  = 0 ; i<n;i++){
            st.insert(nums[i]);
       }
   
       for(int i = 0;i<n;i++){
        if(i!=0 && nums[i]==nums[i-1])continue;
        if(st.find(nums[i]+1) != st.end()){
            cnt++;
        }else{
            ans = max(cnt,ans);
            cnt = 1;
        }
       }
       return max(ans,cnt);
    }
};