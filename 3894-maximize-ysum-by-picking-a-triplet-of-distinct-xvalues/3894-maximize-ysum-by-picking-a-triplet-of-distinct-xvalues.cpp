class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        unordered_map<int, int> mp;
    
        int n = x.size();
        for (int i = 0; i < n; i++) {
            if (mp.find(x[i]) == mp.end()) {
                mp[x[i]] = y[i];
            } else {
                mp[x[i]] = max(mp[x[i]], y[i]);
            }
        }
    
        
        vector<int> maxY;
        for (auto& pair : mp) {
            maxY.push_back(pair.second);
        }
    
        
        if (maxY.size() < 3) return -1;
    
        
        sort(maxY.begin(), maxY.end(),greater());
        
        return maxY[0]+maxY[1]+maxY[2];
    }
};