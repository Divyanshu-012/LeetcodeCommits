class Solution {
public:
    char dfs(unordered_map<char,vector<char>>adj,char ch,vector<int>&vis){
        vis[ch-'a'] = 1;

        char min_char = ch;

        for(auto it : adj[ch]){
            if(vis[it-'a']==0){
                min_char = min(min_char,dfs(adj,it,vis));
            }
        }
        return min_char;

    }
    string smallestEquivalentString(string s1, string s2, string b) {
        int n = s1.size();
        int m= b.size();
        unordered_map<char,vector<char>>adj;

        for(int i = 0 ; i< s1.size();i++){
            int u = s1[i];
            int v = s2[i];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        string ans;
        for(int i = 0 ; i <m; i++){
            vector<int>vis(26,0);
            char ch= b[i];
            char res = dfs(adj,ch,vis);
            
            ans.push_back(res);
        }
        return ans;
    }
};