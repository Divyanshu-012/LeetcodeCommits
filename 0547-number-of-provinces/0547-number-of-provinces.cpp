class Solution {
public:
    void dfs(int idx,vector<int>&vis,unordered_map<int,vector<int>>&adj){
        vis[idx] = true;

        for(auto ngh: adj[idx]){
            if(!vis[ngh]){
                
                dfs(ngh,vis,adj);
            }
            
        }
    }
    int findCircleNum(vector<vector<int>>& isC) {
        int n = isC.size();
        int cnt = 0;
        unordered_map<int,vector<int>>adj;

        for(int i = 0; i<n;i++){
            for(int j = 0; j<n;j++){
                if(isC[i][j] == 1 && i!=j){
                    adj[i].push_back(j);
                   
                }
               
            }
        }
        
    vector<int>vis(n,false);
        for(int i = 0 ; i<n;i++){
           
            if(!vis[i]){
                cnt++;
                dfs(i,vis,adj);
            }
            
        }

        return cnt;
    }
};