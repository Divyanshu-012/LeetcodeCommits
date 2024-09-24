class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        int m=wordDict.size();
        vector<string> ret;
        vector<bool> matched(m,true);
        string str="";
        sol(s,wordDict,0,str,matched,0,ret);        
        return ret;
    }
    void sol(string &s,vector<string> &wordDict,int curr,string &str,vector<bool> &matched,int wordcurr,vector<string> &ret){
        if(curr==s.size() && wordcurr==0) {
            ret.push_back(str);
            return;
        }
        if(curr==s.size()) return; 
        bool added=false;
        vector<bool> copymatched(matched.size(),true);
        string str2="";
        for(int i=0;i<matched.size();i++){
            if(matched[i]){
                if(!added && wordDict[i][wordcurr]==s[curr]){
                    str+=s[curr];
                    str2=str;
                    added=true;
                }
                if(wordDict[i][wordcurr]==s[curr] && wordcurr==wordDict[i].size()-1){
                    if(curr!=s.size()-1){
                    str+=" ";
                    }
                    sol(s,wordDict,curr+1,str,copymatched,0,ret);
                    str=str.substr(0,str.size()-1);
                    matched[i]=false;
                }
                else if(wordDict[i][wordcurr]!=s[curr]){
                    matched[i]=false;
                }
            }
        }
        bool allunmatched=true;
        for(int i=0;i<matched.size();i++){
            if(matched[i]) allunmatched=false;
        }
        if(allunmatched) return;
        sol(s,wordDict,curr+1,str2,matched,wordcurr+1,ret);
    }
};