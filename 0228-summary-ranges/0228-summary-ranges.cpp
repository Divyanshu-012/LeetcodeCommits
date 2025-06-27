class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ans;
        int n = nums.size();
        if(n==0) return {};
        
        int one = nums[0];
        string s = "";
        s+= to_string(one);
        

        int cnt = 1;
        for(long long i = 1;i<n;i++){

            if (nums[i] != nums[i - 1] + 1){
                if(cnt==1){
                    ans.push_back(s);
                    s="";
                    s+=to_string(nums[i]);
                }
                else{
                    int  app = nums[i-1];
                    s += "->";
                    s += to_string(app);

                     ans.push_back(s);
                     s ="";

                     s += to_string(nums[i]);
                     cnt = 1;
                }
               


                // s=nums[i];
            }else{
                cnt++;
            }
        }
        if(cnt >1) {
            s+= "->";
            s+= to_string(nums[n-1]);
            ans.push_back(s);
        }else{
            ans.push_back(s);
        }
        
        return ans;
    }
};