class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;  // Number of courses
        vector<vector<int>> adj(V);  // Adjacency list

        // Build the adjacency list
        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }

        // Create indegree array
        vector<int> indegree(V, 0);
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        // Push all nodes with indegree 0 into the queue
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            // Reduce indegree of neighbors
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        // If topological sort includes all nodes, return true (no cycle)
        return topo.size() == V;
    }
};
