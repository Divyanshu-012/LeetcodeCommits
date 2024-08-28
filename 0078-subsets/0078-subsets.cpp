class Solution {
public:

    void set(int ind,vector<int>&nums,vector<int>&ds,vector<vector<int>>&ans)
    {
        if(ind == nums.size()){
            ans.push_back(ds);
            return ;
        }

        
            ds.push_back(nums[ind]);
            set( ind+1 , nums ,ds, ans);
            ds.pop_back();
            
        
        set( ind +1, nums ,ds, ans);

          


        

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ds;
        vector<vector<int>>ans;
        set(0,nums,ds,ans);
        return ans;
        
    }
};