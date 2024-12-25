
class UnionFind {
public:
    unordered_map<int, int> uf;

    int find(int a) {
        if(!uf.count(a))
            uf[a] = a;
        if(uf[a] != a)
            uf[a] = find(uf[a]);
        return uf[a];
    }
    void merge(int a, int b) {
        uf[find(b)] = find(a);
    }
};


class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        auto uf = UnionFind();
        vector<vector<int>> graph(n+1);
        for(auto edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            uf.merge(edge[0], edge[1]);
        }
        
        vector<int> max_groups(n+1, 0);
        for(int i = 1; i < n+1; i++) {
            deque<pair<int, int>> queue = {{i, 1}};
            vector<int> visited(n+1, 0);
            visited[i] = 1;
            while(!queue.empty()) {
                auto pop = queue.front();
                int cur = pop.first, level = pop.second;
                queue.pop_front();
                for(auto& edge: graph[cur]) {
                    if(!visited[edge]) {
                        queue.push_back({edge, level+1});
                        visited[edge] = level+1;
                    }

                    if(level == visited[edge])
                        return -1;
                }
                int root = uf.find(i);
                max_groups[root] = max(max_groups[root], level);
            }
        }
        int res = 0;
        for(int ele: max_groups)
            res+=ele;
        return res;
    }
};
