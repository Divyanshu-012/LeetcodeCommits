class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp.insert({0,1});
        int Csum = 0;
        int res = 0;

        for(int  i = 0;i<nums.size();i++){

            Csum += nums[i];

            if(mp.find(Csum - k) != mp.end()){
                res += mp[Csum - k];
               
            }
            mp[Csum]++;
        }
        
        return res;
        
    }
};