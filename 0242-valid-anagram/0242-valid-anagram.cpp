class Solution {
public:
    bool isAnagram(string s, string t) {
        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());

        // return s == t;

        unordered_map<char, int> count;
        
       
        for (auto x : s) {
            count[x]++;
        }
        
        
        for (auto x : t) {
            count[x]--;
        }
        
        for (auto x : count) {
            if (x.second != 0) {
                return false;
            }
        }
        
        return true;
        
    }
};