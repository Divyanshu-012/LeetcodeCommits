class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;

        vector<vector<pair<int, int>>> graph(n);
        for (auto& road : roads) {
            int u = road[0];
            int v = road[1];
            int w = road[2];
            graph[u].emplace_back(v,w);
            graph[v].emplace_back(u,w);
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>,greater<>>minHeap;

        vector<long long> res(n, LLONG_MAX);


        vector<int> Count(n, 0);

        res[0] = 0;  // Dist to source is 0
        Count[0] = 1;     // 1 way to reach node 0

        minHeap.emplace(0, 0);  

        while (!minHeap.empty()) {
            long long currTime = minHeap.top().first;  
            int currNode = minHeap.top().second;
            minHeap.pop();

            if (currTime > res[currNode]) continue;

            for (auto& [neighborNode, roadTime] : graph[currNode]) {
                
                if (currTime + roadTime < res[neighborNode]) {
                    res[neighborNode] = currTime + roadTime;
                    Count[neighborNode] = Count[currNode];
                    minHeap.emplace(res[neighborNode], neighborNode);
                }
                
                else if (currTime + roadTime == res[neighborNode]) {
                    Count[neighborNode] =(Count[neighborNode] + Count[currNode]) % MOD;
                }
            }
        }

        return Count[n - 1];
    }
};