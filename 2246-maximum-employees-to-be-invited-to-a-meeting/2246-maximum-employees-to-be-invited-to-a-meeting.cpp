class Solution {
public:
    int BFS(int start, unordered_map<int, vector<int>>& adj, vector<bool> & visited){
        queue<pair<int,int>> q;
        q.push({start,0});
        int maxDist = 0;

        while(!q.empty()){
            auto[currNode, dist] = q.front();
            q.pop();

            for(auto ngbr : adj[currNode]){
                if(!visited[ngbr]){
                    visited[ngbr] = true;
                    q.push({ngbr,dist+1});
                    maxDist = max(maxDist,dist+1);
                }
            }
        }

        return maxDist;

    }
    int maximumInvitations(vector<int>& fav) {
        int n = fav.size();
        unordered_map<int,vector<int>> adj;

        for(int i = 0; i< n;i++){
            int u = i;
            int v = fav[i];
            // adj[u].push_back(v);
            // but we need reveresed graph so -->
            adj[v].push_back(u);
        }

        int longestCycleCnt = 0;
        int happyCplCnt = 0; // if cycle len == 2 then what is the total count !!

        vector<bool>vis(n,false);
        for(int i = 0 ; i< n;i++){
            if(!vis[i]){
                // {node,abtak node ka count }
                unordered_map<int,int>mp;

                int currNode = i;
                int currNodeCnt = 0;

                while(!vis[currNode]){ // until cycle is not detected
                    vis[currNode] = true;
                    mp[currNode] = currNodeCnt;

                    int nextNode = fav[currNode];// fav node of curr node
                    currNodeCnt +=1;

                    if(mp.count(nextNode)){ // already visited hai ye. Matlab cycle detect ho gya hai 
                        int cycleLength = currNodeCnt - mp[nextNode];

                        longestCycleCnt = max(longestCycleCnt,cycleLength);

                        if(cycleLength == 2){ // happy couple case
                            // currnode <-> nextNode = 2 node
                            vector<bool> visited(n,false);

                            visited[currNode] = true;
                            visited[nextNode] = true;
                            happyCplCnt += 2 + BFS(currNode, adj, visited) + BFS(nextNode, adj,visited);
                        }
                        break;
   
                    }
                    currNode = nextNode;
                }
            }
        }
        return max(happyCplCnt,longestCycleCnt);
        
    }
};