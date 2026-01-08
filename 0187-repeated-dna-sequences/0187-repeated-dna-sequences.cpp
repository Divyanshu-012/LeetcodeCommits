class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size()<10) return{};
        unordered_set<string> res;
        unordered_set<string>seen;
        for(int i=0;(int)i<=s.size()-10;i++){
            string seq=s.substr(i,10);
            if(seen.contains(seq)){
                res.insert(seq);
            }
            seen.insert(seq);
        }

        return {res.begin(),res.end()};
    }
};