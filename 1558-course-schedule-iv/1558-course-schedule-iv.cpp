class Solution {
public:
    void DFS(int s, vector<vector<int>>& adj, vector<vector<bool>>& reachable) {
        for (int ngbr : adj[s]) {
            if (!reachable[s][ngbr]) {
                reachable[s][ngbr] = true;
                DFS(ngbr, adj, reachable);
                for (int i = 0; i < reachable.size(); i++) {
                    if (reachable[ngbr][i]) {
                        reachable[s][i] = true;
                    }
                }
            }
        }
    }
    
    vector<bool> checkIfPrerequisite(int nums, vector<vector<int>>& pre, vector<vector<int>>& q) {
        vector<vector<int>> adj(nums);
        for (int i = 0; i < pre.size(); i++) {
            int u = pre[i][0];
            int v = pre[i][1];
            adj[u].push_back(v);
        }

        vector<vector<bool>> reachable(nums, vector<bool>(nums, false));
        for (int i = 0; i < nums; i++) {
            DFS(i, adj, reachable);
        }

        vector<bool> ans;
        for (int i = 0; i < q.size(); i++) {
            int u = q[i][0];
            int v = q[i][1];
            ans.push_back(reachable[u][v]);
        }
        
        return ans;
    }
};
