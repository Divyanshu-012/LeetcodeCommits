class Solution {
public:
    unordered_map<int, vector<int>>adj;
    unordered_map<int,int>bobMap;
    int aliceIncome;

    bool DFSBob(int curr, int t, vector<bool>&vis){
        vis[curr] = true;
        bobMap[curr] = t;

        if(curr == 0){
            return true;
        }

        for(auto it: adj[curr]){
            if(!vis[it]){
                if(DFSBob(it , t+1, vis) == true){
                    return true;
                }
            }
        }

        bobMap.erase(curr);
        return false;
    }

    void DFSAlice(int curr, int t ,int income,  vector<bool> & vis, vector<int>& amount){
        vis[curr] = true;

        if(bobMap.find(curr) == bobMap.end() || t < bobMap[curr]){
            income += amount[curr];
        } else if ( t == bobMap[curr]){
            income += (amount[curr]/2);
        }

        if(adj[curr].size() == 1 && curr != 0){ //leaf node
            aliceIncome = max(aliceIncome, income);
        }

        for(int &ngbr : adj[curr]){
            if(!vis[ngbr]){
                DFSAlice(ngbr, t+1, income, vis,amount);
            }
        }
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size(); // no. of nodes 

        aliceIncome = INT_MIN ;
        for(vector<int> & edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        //DFS ON FINDING TIME TO REACH EACH NODE TILL 0
        int time = 0;
        vector<bool>vis(n,false);
        DFSBob(bob, time,vis);

        int income = 0;
        vis.assign(n,false);
        DFSAlice( 0, 0, income,vis, amount);

        return aliceIncome;
    }
};