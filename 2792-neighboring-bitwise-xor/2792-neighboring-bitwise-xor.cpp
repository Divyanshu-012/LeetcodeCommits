class Solution {
public:
    bool doesValidArrayExist(vector<int>& d) {
        if(d.size() == 1) return d[0] == 0;
        
        vector<int> ans;
        int n = d.size();
        
        
        if(d[0] == 1) {
            ans.push_back(0);
            ans.push_back(1);
        } else {
            ans.push_back(0);
            ans.push_back(0);
        }
        
        // Build the ans vector
        for(int i = 1; i < n; i++) {
            if(ans.back() == 1) {
                ans.push_back(d[i] == 1 ? 0 : 1);
            } else {
                ans.push_back(d[i] == 1 ? 1 : 0);
            }
        }
        
      
        return d[n-1] == (ans[n-1] ^ ans[0]);
    }
};
