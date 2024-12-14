class Solution {
private:
    bool dfs(int node, vector<vector<int>>&graph,vector<int>&vis){
        int n = graph.size();
        if(vis[node] != 0){
            return vis[node] == 1;
        }

        vis[node] = 2;

        for(int neighbour : graph[node]){
            if(!dfs(neighbour,graph,vis)){
                return false;
            }
        }

    vis[node] = 1;
    return true;
         
        
        
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>vis(n,0);
        vector<int> safenodes;
        for(int i = 0;  i< n; i++){
            if(dfs(i,graph,vis) ){
                safenodes.push_back(i);
            }

        }

        return safenodes;
    }
};