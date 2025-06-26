class Solution {
public:
    bool wordPattern(string pattern, string s) 
    {
        int n=s.size();
        vector<string>words;
        int start=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                string temp=s.substr(start,i-start);
                words.push_back(temp);
                start=i+1;
            }
        }    
        words.push_back(s.substr(start,n-start));

        map<char,string>mpp;
        set<string>used;
        if(pattern.size()<words.size() || pattern.size()>words.size()) return false;

        for(int i=0;i<pattern.size();i++){
            if(mpp.find(pattern[i])==mpp.end()){
                mpp[pattern[i]]=words[i];
                if(used.count(words[i])) return false;
                used.insert(words[i]);
            }
            else if(mpp[pattern[i]]!=words[i])
                return false;
        }
        return true;
    }
};