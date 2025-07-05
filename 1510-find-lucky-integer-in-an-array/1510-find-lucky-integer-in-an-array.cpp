class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int>mp;
        for(int i =0 ; i<n;i++){
            mp[arr[i]]++;
        }
        int ans = -1;
        for(auto it : mp){
            int val = it.first;
            int fr = it.second;

            if(val == fr){
                ans = max(ans,val);
            } 
            
        }
        return ans;
    }
};