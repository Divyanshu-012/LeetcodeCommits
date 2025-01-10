class Solution {
public:
    bool isadj(string& a, string& b){
        int c=0, n=a.size();
        for(int i=0;i<n;i++){
            if(a[i]!=b[i]) c++;
        }
        return c==1;
    }

    void dfs(string& s, map<string, vector<string>>& par, string& startWord, vector<string>& v, vector<vector<string>>& ans){
        if(s==startWord){
            ans.push_back(v);
            return;
        }
        else{
            for(string p: par[s]){
                v.push_back(p);
                dfs(p, par, startWord, v, ans);
                v.pop_back();
            }
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        map<string, vector<string>> m;
        int start=-1,end=-1;
        vector<vector<string>> ans;
        map<string, int> dist;
        map<string, vector<string>> par;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isadj(wordList[i], wordList[j])){
                    m[wordList[i]].push_back(wordList[j]);
                    m[wordList[j]].push_back(wordList[i]);
                }
            }
            dist[wordList[i]] = INT_MAX;
            if(wordList[i]==beginWord){
                start = i;
            }
            if(wordList[i]==endWord){
                end = i;
                dist[beginWord] = 0;
            }
        }
        if(end==-1) return ans;
        if(start==-1){
            wordList.push_back(beginWord);
            start = n;
            n++;
            for(string s: wordList){
                if(isadj(beginWord,s)){
                    m[beginWord].push_back(s);
                }
            }
        }
        queue<string> q;
        q.push(beginWord);
        dist[beginWord]=0;
        bool b = false;
        while(!q.empty()){
            int ss = q.size();
            for(int i=0;i<ss;i++){
                string t = q.front();
                q.pop();
                if(t==endWord){
                    b = true;
                }
                for(string s: m[t]){
                    if(dist[s]>dist[t]+1){
                        par[s] = {t};
                        dist[s] = dist[t]+1;
                        q.push(s);
                    }
                    else if(dist[s]==dist[t]+1){
                        par[s].push_back(t);
                    }
                }
            }
            if(b){
                break;
            }
        }
        if(b){
            vector<string> v = {endWord};
            dfs(endWord, par, beginWord, v, ans);
            vector<vector<string>> ret;
            for(auto vec: ans){
                reverse(vec.begin(), vec.end());
                ret.push_back(vec);
            }
            return ret;
        }
        else{
            return {};
        }
    }
};