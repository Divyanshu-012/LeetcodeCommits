class Solution {
public:
    bool canConstruct(string s, int k) {
        unordered_map<char,int> mp;

        if (s.size() < k) return false;

        for(auto ch: s){
            mp[ch]++;
        }

        int cntO = 0, cntE = 0;
        for(auto it : mp){
            if((it.second % 2 ) != 0) cntO++;
            else cntE++;

        }

        if (cntO <= k ) return true; 

        return false;
    }
};