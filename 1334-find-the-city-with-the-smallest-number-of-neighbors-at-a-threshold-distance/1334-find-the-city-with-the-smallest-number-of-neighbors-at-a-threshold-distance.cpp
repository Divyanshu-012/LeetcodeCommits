class Solution {
public:

    void dijsktra(vector<vector<pair<int, int>>> &graph,int S,vector<int>&res){

      priority_queue<pair<long long, int>, vector<pair<long long, int>>,greater<>>q;

        fill(res.begin(),res.end(),1e4+7);

        q.emplace(0, S);  

        while(!q.empty()){
          auto [dist, node] = q.top();
          q.pop();

          for(auto & [ngr, wei] : graph[node]){
            if( (dist + wei)< res[ngr]  ){
              res[ngr] = dist+wei;
              q.emplace(res[ngr],ngr);

            }
            
          }

        }
    }
    int findTheCity(int n, vector<vector<int>>& edges, int d) {

        vector<vector<pair<int, int>>> graph(n);

        for (auto& road : edges) {
            int u = road[0];
            int v = road[1];
            int w = road[2];
            graph[u].emplace_back(v,w);
            graph[v].emplace_back(u,w);
        }

        vector<vector<int>>DSM(n,vector<int>(n,1e4));

        for(int i = 0;i<n;i++){
          dijsktra(graph,i,DSM[i]);
        }

        int minCnt = 1000+7;
        int ans = -1;
        for(int i = 0; i<n;i++){
          int cnt = 0;
          for(int j = 0;j<n;j++){
            if(i!=j && DSM[i][j] <= d){
              cnt++;
            }
          }
          if(cnt <= minCnt){
            minCnt = cnt;
            ans = i;
          }
          
        }
        return ans;


        
    }
};