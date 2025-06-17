class Solution {
public:
    bool canConstruct(string n, string m) {
        if(m.size()< n.size())return false;

        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;
        for(auto it : n){
            mp1[it]++;
        }

        for(auto it : m){
            mp2[it]++;
        }

         for(auto it : mp1) {
            char ch = it.first;
            int freq = it.second;
            if(mp2[ch] < freq) return false;
        }
        return true;
    }
};