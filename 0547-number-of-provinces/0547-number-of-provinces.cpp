class Solution {
public:

    void dfs(int node, vector<int> &vis,vector<vector<int>> &adjLs){
        
        vis[node] = 1;
        for(auto it : adjLs[node]){
            if(!vis[it]){
                dfs(it, vis, adjLs);   
            }

        }

    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int V = isConnected.size(); 
        vector<vector<int>> adjLs(V); // Adjacency list
        
        for(int i = 0; i<V;i++){
            for(int  j = 0 ; j< V; j++){
                if(isConnected[i][j] == 1 && i!=j){
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
        vector<int> vis(V,0);
        int cnt = 0;
        for(int  i = 0 ; i< V;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,vis,adjLs);
            }
        }
        return cnt;
    }
};