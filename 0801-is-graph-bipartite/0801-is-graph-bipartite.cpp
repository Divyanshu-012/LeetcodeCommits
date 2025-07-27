class Solution {
public:
    bool dfs(int v, vector<vector<int>>&graph,vector<int>&vis){
        
        
        for(auto it:graph[v]){
            if(vis[it] == vis[v]){
                return false;
            }
            if(vis[it] == -1){
                vis[it] = 1- vis[v];
                if(dfs(it,graph,vis)==false) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>vis(n,-1);

        for(int i = 0;i<n;i++){
            if(vis[i] == -1){
                vis[i]=1;
                if(dfs(i,graph,vis)== false) return false;
            }
        }
    return true;
    }
};