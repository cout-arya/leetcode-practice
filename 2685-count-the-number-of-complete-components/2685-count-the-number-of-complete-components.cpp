class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int ans = 0;
        vector<vector<int>> adj(n);
        vector<int> vis(n, 0);
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for (int i = 0; i < n; i++) {
            if (vis[i] == 1)
                continue;
            vis[i] = 1;
            queue<int> q;
            q.push(i);
            int cnt = 0;
            int degreeSum = 0;
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                cnt++;
                degreeSum += adj[node].size();
                for (auto& it : adj[node]) {
                    if (!vis[it]) {
                        vis[it] = 1;
                        q.push(it);
                    }
                }
            }
            int sum = degreeSum / 2;
            if (sum == (cnt * (cnt - 1)) / 2) {
                ans++;
            }
        }
        return ans;
    }
};