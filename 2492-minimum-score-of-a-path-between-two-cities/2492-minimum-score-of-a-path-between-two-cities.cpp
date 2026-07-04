class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& e : roads) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        queue<int> q;
        vector<int> vis(n + 1, 0);
        q.push(1);
        vis[1] = 1;
        int ans = INT_MAX;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto& it : adj[node]) {
                int adjNode = it.first;
                int wt = it.second;
                ans = min(ans, wt);
                if (!vis[adjNode]) {
                    vis[adjNode] = 1;
                    q.push(adjNode);
                }
            }
        }
        return ans;
    }
};