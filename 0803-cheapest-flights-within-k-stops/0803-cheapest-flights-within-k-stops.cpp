class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>>adj;

        for(auto it : flights){
            int u = it[0];
            int v = it[1];
            int w = it[2];

            adj[u].push_back({v,w});

        }

        vector<int>dist(n,INT_MAX);
        dist[src] = 0;

        queue<pair<int,int>>q;
        q.push({src,0});

        int steps = 0;

        while(!q.empty() && steps <= k){

            int N = q.size();
            while(N--){
                int node = q.front().first;
                int wgt = q.front().second;
                q.pop();

                for(auto ngbr : adj[node]){
                    int u = ngbr.first;
                    int w = ngbr.second;

                    if(w + wgt < dist[u]){
                        dist[u] = w + wgt;

                        q.push({u,w+wgt});
                    }
                }

            }
            steps++;
              
        }
        if(dist[dst] == INT_MAX)return -1;
        return dist[dst];
    }
};